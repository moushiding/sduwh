import requests
import re
import json


url = "https://qyapi.weixin.qq.com/cgi-bin/gettoken?corpid=wwed63b2b1aa71c2e1&" \
      "corpsecret=Z9RiV77BeuGbi3rri-CdAh1iaHwvefuX0X5fgH1ebXo"

payload={}
headers = {}

response = requests.request("GET", url, headers=headers, data=payload)



print(response.text)
print(type(response.text))


str1 = re.findall(r"access_token\":\"(.*?)\",\"", response.text)
str2 = ' '.join(str1)
str3 = "https://qyapi.weixin.qq.com/cgi-bin/message/send?access_token="+str2



url = str3

payload = json.dumps({
  "touser": "YangLiWen",
  "toparty": "@all",
   "totag" : "@all",
  "msgtype": "text",
  "agentid": 1000002,
  "text": {
    "content": "hhhhhhh"
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