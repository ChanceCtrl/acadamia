from flask import Flask, request, jsonify

app = Flask(__name__)

# Storage for messages
aboutme = {"name": "Chance", "hometown": "Atlanta", "favorite_class": "bed 1001"}
comments = []
global autoreply
autoreply = False


@app.route("/")
def home():
    try:
        return "Hello, World.", 200
    except:
        return "", 404


@app.route("/whoami")
def showprofile():
    try:
        return jsonify(aboutme), 200
    except:
        return "", 404


@app.route("/textme", methods=["POST"])
def post_comment():
    if not request.is_json:
        return "", 400

    data = request.get_json()
    message = data.get("message")

    if not message:
        return "", 401

    # Store the message in the comments array
    try:
        comments.append(message)

        global autoreply
        if autoreply:
            if data.get("hometown") == aboutme.get("hometown"):
                return "Hi, thanks for the message neighbor.", 201
            else:
                return "Hi, thanks for the message.", 201
        else:
            return "", 201
    except:
        return "", 400


@app.route("/listmessages")
def showfeed():
    try:
        return jsonify({"comments": comments}), 200
    except:
        return "", 404


@app.route("/autoreply/on")
def set_autoreply_on():
    try:
        global autoreply
        autoreply = True
        return "", 200
    except:
        return "", 404


@app.route("/autoreply/off")
def set_autoreply_off():
    try:
        global autoreply
        autoreply = False
        return "", 200
    except:
        return "", 404


if __name__ == "__main__":
    HOST = "40.20.3.42"  # Use '0.0.0.0' to make the server accessible externally
    PORT = 4020  # Set your desired port number
    app.run(host=HOST, port=PORT, debug=True)
