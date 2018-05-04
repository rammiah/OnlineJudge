import requests
req = requests.get("http://www.baidu.com")

print(req.status_code)

print(req.text)
sess = requests.session()
sess.get(url)
