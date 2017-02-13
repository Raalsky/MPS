from django.db import models

class Medicine(models.Model):
    EAN             = models.BigIntegerField(primary_key=True)
    Name            = models.CharField(max_length=100)
    CommonName      = models.CharField(max_length=100)
    Potency         = models.CharField(max_length=100)
    Description     = models.CharField(max_length=100)
    Validity        = models.CharField(max_length=15)
    ProcedureType   = models.CharField(max_length=20)
    AuthorizationNr = models.CharField(max_length=10)
    ATC             = models.CharField(max_length=15)
    Manufacturer    = models.CharField(max_length=100)
    Package         = models.CharField(max_length=100)
    Type            = models.CharField(max_length=5)
    RefundValue     = models.FloatField()

    class Meta:
        db_table = 'Medicines'

class PostalCode(models.Model):
    PostalCode      = models.CharField(primary_key=True,max_length=6)
    Province        = models.CharField(null=False,max_length=25)
    City            = models.CharField(null=False,max_length=25)

    class Meta:
        db_table    = 'PostalCodes'
