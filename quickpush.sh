!/bin/bash

echo "What is the message of commit:"

read message
datep=$(date)

commitMessage=$($message + $datep)

git add .

git commit -m commitMessage

git push