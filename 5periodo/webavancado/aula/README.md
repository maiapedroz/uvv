### Comandos para rodar o app web atraves de um ambiente virtual:


```
py -m venv venv
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
venv\Scripts\activate
py -m pip install --upgrade pip
pip install flask
pip install ipython
pip install flask-wtf
set FLASK_APP=bloguvv.py
$env:FLASK_DEBUG = 1
flask run
```

