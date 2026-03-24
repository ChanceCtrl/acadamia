import requests

# Flask server details
url = "http://40.20.3.25:4020/textme"

# JSON payload to send
data = {
    "name": "tester",
    "hometown": "Atlanta, GA",
    "message": "mrow mrwo mrwomrwomrwomrow",
}

try:
    # Send POST request
    response = requests.post(url, json=data)

    # Print response details
    print("Status Code:", response.status_code)
    print("Response Body (Content):", response.content)
    print("Response Body (Text):", response.text)
except requests.exceptions.RequestException as e:
    print("An error occurred:", e)
