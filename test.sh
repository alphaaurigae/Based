#!/bin/bash

BIN_DIR='bin'
BIN_NAME='based_encode-decode'


echo ""
echo "Test w.o arg"
${BIN_DIR}/${BIN_NAME}
echo ""
echo "Decode a string of 68656c6c6f w.o setting --hex (exp hex 872a92a3091bcc)"
${BIN_DIR}/${BIN_NAME} -d '68656c6c6f'
echo ""
echo "Encode hex input"
${BIN_DIR}/${BIN_NAME} --hex '68656c6c6f'
echo ""
echo "Encode input not hex w. --hex set (exp fail)"
${BIN_DIR}/${BIN_NAME} --hex 'Cn8eVZg'
echo ""
echo "Decode Cn8eVZg exp hello && hex 68656c6c6f"
${BIN_DIR}/${BIN_NAME} -d  'Cn8eVZg'
echo ""
echo "Encode hello exp Cn8eVZg"
${BIN_DIR}/${BIN_NAME} 'hello'
echo ""
