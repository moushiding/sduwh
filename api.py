# -*- encoding:utf-8 -*-
import requests
import yaml
import json

config_file = open("config.yaml", "r", encoding="utf-8")
config = yaml.load(config_file.read(), Loader=yaml.FullLoader)
config_file.close()
corpid = config["corpid"]
corpsecret = config["corpsecret"]
receive_token = config["receive_token"]
AESKey = config["AESKey"]


def get_token():
    res = requests.get(
        "https://qyapi.weixin.qq.com/cgi-bin/gettoken?corpid=%s" % corpid + "&corpsecret=%s" % corpsecret)
    return res.json()['access_token']


def send_message_all(message, token):
    
   url="https://qyapi.weixin.qq.com/cgi-bin/message/send?access_token="+token
    
   payload = json.dumps({
  "touser": "@all",
  "toparty": "@all",
   "totag" : "@all",
  "msgtype": "text",
  "agentid": 1000002,
  "text": {
    "content": "%s"% message
  },
  "safe": 0,
  "enable_id_trans": 0,
  "enable_duplicate_check": 0,
  "duplicate_check_interval": 1800
 })
   headers = {
  'Content-Type': 'application/json'
   }
   response = requests.request("POST", url, headers=headers, data=payload)

   print(response.text)

def send_message_someone(message, token):
    
   url="https://qyapi.weixin.qq.com/cgi-bin/message/send?access_token="+token
    
   payload = json.dumps({
  "touser": "someone",
  "toparty": "@all",
   "totag" : "@all",
  "msgtype": "text",
  "agentid": 1000002,
  "text": {
    "content": "%s"% message
  },
  "safe": 0,
  "enable_id_trans": 0,
  "enable_duplicate_check": 0,
  "duplicate_check_interval": 1800
 })
   headers = {
  'Content-Type': 'application/json'
   }
   response = requests.request("POST", url, headers=headers, data=payload)

   print(response.text)