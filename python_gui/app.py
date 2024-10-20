from flask import Flask, request, jsonify
from twilio.twiml.messaging_response import MessagingResponse

app = Flask(__name__)
messages = []
@app.route("/sms", methods =['POST'])
def sms_reply():
    msg = request.form.get('Body')
    from_number = request.form.get("From")

    messages.append({'from':from_number,'message':msg})

    resp = MessagingResponse()
    resp.message("Message received")
    return str(resp)
@app.route("/messages", methods =['GET'])
def get_messages():
    return jsonify(messages)
if __name__ =="__main__":
 app.run(debug = True)