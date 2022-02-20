import base64
encrypted="EgkSHgIQDV0AQkkUQUwGAQ1PB0JFDkYIDh8ESxICHEtGS1tTT0sAEQxLDA4FVEQOVAAPSA4ZFQBP DklFTkcPCBMWDEcRCQwJTUtGEgtGGgAfSwwODwdPDklFTlsPBw4QA0sXQkUORhkAEQpHBxZODltL RgAJSBZCRQ5GDQ4cTw5JRU5ZCAVAVBU="
my_eyes=str.encode("i.akash.se")
decoded=base64.b64decode(encrypted)
decrypted=""
for i in range(0,len(decoded)):
  decrypted+=chr((my_eyes[i%len(my_eyes)] ^ decoded[i]))
print(decrypted)