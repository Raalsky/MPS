# MedicalPrescriptionsSystem

## Autorzy
* Łukasz Kowalski
* Rafał Jankowski

# Diagram
![Database Diagram](diagram.png)

# Kod SQL
### Tabela Adresses
```sql
CREATE TABLE Adresses
(
    PostalCode CHAR(6) PRIMARY KEY NOT NULL,
    Province NVARCHAR(25) NOT NULL,
    City NVARCHAR(25) NOT NULL,
    Allocation NVARCHAR(50)
);
```
