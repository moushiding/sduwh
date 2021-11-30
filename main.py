# -*- encoding:utf-8 -*-
import datetime
from flask import Flask, request, jsonify, make_response
import requests, re, os, random
import json
import api
from WXBizMsgCrypt import WXBizMsgCrypt, XMLParse, ET
from urllib.parse import unquote
from threading import Timer




app = Flask(__name__)
token = api.get_token()
my_crypt = WXBizMsgCrypt(api.receive_token, api.AESKey, api.corpid)



    
def UpdateToken():
    token = api.get_token()
    t = Timer(7200, UpdateToken)
    t.start()


@app.route('/', methods=["GET"])
def check():
    if request.method == 'GET':
        
        # 取出数据
        msg_signature = request.args.get('msg_signature')
        timestamp = request.args.get('timestamp')
        nonce = request.args.get('nonce')
        echostr = request.args.get('echostr')
        
        # 验证URL
        ret, content = my_crypt.VerifyURL(msg_signature, timestamp, nonce, echostr)
        
        response = make_response(content)
        
        
        return response


@app.route('/', methods=["POST"])
def receive():
    if request.method == 'POST':
        msg_signature = request.args.get('msg_signature')
        timestamp = request.args.get('timestamp')
        nonce = request.args.get('nonce')
        
        
        ret, xml_content = my_crypt.DecryptMsg(request.get_data(), msg_signature, timestamp, nonce)
        
        
        content = ET.fromstring(xml_content).find("Content")
        
        
        user = ET.fromstring(xml_content).find("FromUserName")
        
        print(xml_content)
        
        response = make_response(jsonify({'message': 'OK'}, 200))
        
        print(user.text+":"+content.text)
        
        api.send_message_someone((
                "" + datetime.datetime.strftime(datetime.datetime.now(),
                                                    "%y-%m-%d %H:%M:%S \n") + "用户：" + user.text + "\n发送消息:" + content.text),
            token)
        
        return response


if __name__ == "__main__":
    
    app.config['SERVER_NAME'] = 'readyforthu.club:8888'

    app.run('0.0.0.0', debug=False, port=8888,
            ssl_context=("readyforthu.club.pem", 'readyforthu.club.key'))
    UpdateToken()
    # 该函数，会在自己的堆栈中，发射一个带计时器的线程再执行自己一次，以此类推，
    # 实现不阻塞主函数的2小时更新token，而且之所以能更新token，也是因为多线程
    # 之间是互相共享全局变量的，你在updatetoken中更新了之后，主线程在执行的时
    # 侯也会对应调取修改之后的数据
