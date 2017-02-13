from django.db import models

class Address(models.Model):
    postalcode = models.CharField(db_column='PostalCode', primary_key=True, max_length=6)
    province = models.CharField(db_column='Province', max_length=25)
    city = models.CharField(db_column='City', max_length=25)

    class Meta:
        db_table = 'Addresses'
