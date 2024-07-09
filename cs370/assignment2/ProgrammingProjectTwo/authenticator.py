import sys
import qrcode
import random
import string
import time
import hmac
import hashlib
import base64

class TOTP:
    def __init__(self, secret_key):
        self.secret_key = base64.b32decode(secret_key.upper())

    def generate_otp(self):
        timestamp = int(time.time()) // 30 
        timestamp_bytes = self._int_to_bytestring(timestamp)
        hash_result = hmac.new(self.secret_key, timestamp_bytes, hashlib.sha1).digest()
        offset = hash_result[-1] & 0xF
        truncated_hash = hash_result[offset : offset + 4]
        otp = self._bytes_to_int(truncated_hash) & 0x7FFFFFFF
        otp %= 10 ** 6
        return "{:06d}".format(otp)

    def _int_to_bytestring(self, integer):
        return "{:016X}".format(integer).encode()

    def _bytes_to_int(self, byte_string):
        return int.from_bytes(byte_string, byteorder='big')


# Generates a qr code from Google Auth
def generateQR():
    user = str('example@google.com')
    issuer = str('Secure App')
    secret = ''.join(random.choice(string.ascii_uppercase) for i in range(32))
    file = open("./secret.txt", "w")
    file.write(secret)
    file.close()
    qrcode.make("otpauth://totp/" + issuer + ":" + user + "?secret=" + secret + "&issuer=" + issuer).save("./qrCode.jpg")
    print("QR Code created!")

# Prints the current OTP every 30 seconds
def getOTP():
    file = open('./secret.txt', 'r')
    for line in file:
        key = line.strip()
    file.close()
    while(True):
        totp = TOTP(key)
        otp = totp.generate_otp()
        print("Current OTP:", otp)
        time.sleep(30)

# main
def main():
    if sys.argv[1] == "--generate-qr":
        generateQR()
    elif sys.argv[1] == "--get-otp":
        getOTP()
    else:
        print("The command you provided was incorrect try --generate-qr or --get-otp")

main()