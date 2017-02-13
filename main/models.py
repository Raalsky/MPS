from django.db import models

class Medicines(models.Model):
    ean     = models.BigIntegerField(primary_key=True)
    name    = models.CharField(max_length=200)

    class Meta:
        db_table = 'Medicines'
