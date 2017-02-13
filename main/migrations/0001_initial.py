# -*- coding: utf-8 -*-
# Generated by Django 1.10.5 on 2017-02-13 18:34
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Medicines',
            fields=[
                ('EAN', models.BigIntegerField(primary_key=True, serialize=False)),
                ('Name', models.CharField(max_length=100)),
                ('CommonName', models.CharField(max_length=100)),
                ('Potency', models.CharField(max_length=100)),
                ('Description', models.CharField(max_length=100)),
                ('Validity', models.CharField(max_length=15)),
                ('ProcedureType', models.CharField(max_length=20)),
                ('AuthorizationNr', models.CharField(max_length=10)),
                ('ATC', models.CharField(max_length=15)),
                ('Manufacturer', models.CharField(max_length=100)),
                ('Package', models.CharField(max_length=100)),
                ('Type', models.CharField(max_length=5)),
                ('RefundValue', models.FloatField()),
            ],
            options={
                'db_table': 'Medicines',
            },
        ),
    ]
