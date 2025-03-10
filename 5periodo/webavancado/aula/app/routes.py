# app/routes.py

from app import app
from flask import render_template
from app.forms import LoginForm

@app.route('/')
@app.route('/index')
def index(): 
    user = {'username': 'Carnaval'}
    posts = [
        {
            'author': {'username': 'Joao'},
            'body': 'Belo dia em Vila Velha!'
        },
        {
            'author': {'username': 'Maria'},
            'body': 'Bora pra folia!'
        }
    ]
    return render_template('index.html', title='Home', user=user, posts = posts)

@app.route('/login')
def login():
    form = LoginForm()
    return render_template('login.html', title='Sign In', form=form)