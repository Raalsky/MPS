from django.db import models

class Addresses(models.Model):
    PostalCode      = models.CharField(null=False, primary_key=True, max_length=6)
    Province        = models.CharField(null=False, max_length=25)
    City            = models.CharField(null=False, max_length=25)

    class Meta:
        db_table    = 'Addresses'


class Wholesale(models.Model):
    WholesaleName   = models.CharField(max_length=50)
    AuthorizationNr = models.CharField(max_length=40)
    CreationDate    = models.DateTimeField('creation date')
    PostalCode      = models.ForeignKey('Addresses')
    Address         = models.CharField(max_length=200)

    class Meta:
        db_table    = 'Wholesales'
