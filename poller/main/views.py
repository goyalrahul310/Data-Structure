
from django.shortcuts import render

from django.views.generic import(
	ListView,DetailView)
# Create your views here.

from main import models

class Index(ListView):
	model = models.Questions
	template_name = 'main/index.html'

class Question(DetailView):
	model = models.Questions 
	template_name = 'main/question.html'
