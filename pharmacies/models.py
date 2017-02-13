from django.db import models
from django.contrib.auth.models import User

class Pharmacy(models.Model):
    Name                = models.CharField(max_length=50)
    Type                = models.CharField(max_length=30)
    AuthorizationNr     = models.CharField(max_length=40)
    CreationDate        = models.DateField()
    AuthorizationDate   = models.DateField()
    PostalCode          = models.ForeignKey('main.PostalCode')
    Street              = models.CharField(max_length=10)

    class Meta:
        db_table = 'Pharmacies'

class Pharmacist(models.Model):
    UserId          = models.ForeignKey(User)
    PharmacyId      = models.ForeignKey(Pharmacy)
    EmploymentDate  = models.DateField()

    class Meta:
        db_table    = "Pharmacists"

class PharmacyProduct(models.Model):
    MedicineId      = models.ForeignKey('main.Medicine')
    PharmacyId      = models.ForeignKey(Pharmacy)
    Price           = models.FloatField()
    class Meta:
        db_table    = "PharmaciesProducts"
