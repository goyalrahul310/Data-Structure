from django.contrib import admin


from main import models

admin.site.register([
	models.Questions,
	models.Choice])