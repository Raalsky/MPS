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

### Tabela Allergies
```sql
CREATE TABLE Allergies
(
    PatientId CHAR(11) NOT NULL,
    MedicineId BIGINT NOT NULL,
    CONSTRAINT PK__Allergie__83FCD1EF2CEB343A PRIMARY KEY (PatientId, MedicineId),
    CONSTRAINT FK__Allergies__Patie__7A3223E8 FOREIGN KEY (PatientId) REFERENCES Patients (PESEL),
    CONSTRAINT FK__Allergies__Medic__7B264821 FOREIGN KEY (MedicineId) REFERENCES Medicines (EAN)
);
```

### Tabela Doctors
```sql
CREATE TABLE Doctors
(
    UserId INT PRIMARY KEY NOT NULL,
    InstitutionId INT NOT NULL,
    Branch NVARCHAR(25),
    EmploymentDate DATE NOT NULL,
    CONSTRAINT FK__Doctors__UserId__5CA1C101 FOREIGN KEY (UserId) REFERENCES Users (UserId),
    CONSTRAINT FK__Doctors__Institu__7755B73D FOREIGN KEY (InstitutionId) REFERENCES Institutions (InstitutionId)
);
```

### Tabela DoctorsAndPatrientsRelation
```sql
CREATE TABLE DoctorsAndPatientsRelation
(
    DoctorId INT NOT NULL,
    PatientId CHAR(11) NOT NULL,
    CONSTRAINT DoctorsAndPatientsRelation_PatientId_DoctorId_pk PRIMARY KEY (DoctorId, PatientId),
    CONSTRAINT FK__DoctorsAn__Docto__6CD828CA FOREIGN KEY (DoctorId) REFERENCES Doctors (UserId),
    CONSTRAINT FK__DoctorsAn__Patie__756D6ECB FOREIGN KEY (PatientId) REFERENCES Patients (PESEL)
);
```

### Tabela EventsTypes
```sql
CREATE TABLE EventsTypes
(
    EventTypeId INT PRIMARY KEY NOT NULL,
    EventName NVARCHAR(50)
);
```

### Tabela Institutions
```sql
CREATE TABLE Institutions
(
    InstitutionId INT PRIMARY KEY NOT NULL IDENTITY,
    InsitutionName NVARCHAR(50) NOT NULL,
    PostalCode CHAR(6) NOT NULL,
    Prefix NVARCHAR(3),
    Street NVARCHAR(25),
    HouseNr VARCHAR(5),
    CONSTRAINT Institutions_Adresses_PostalCode_fk FOREIGN KEY (PostalCode) REFERENCES Adresses (PostalCode)
);
```

### Tabela MedicalEvents
```sql
CREATE TABLE MedicalEvents
(
    MedicalEventId INT PRIMARY KEY NOT NULL IDENTITY,
    PatientId CHAR(11) NOT NULL,
    EventType INT NOT NULL,
    EventBegin DATE NOT NULL,
    EventEnd DATE NOT NULL,
    Description TEXT,
    CONSTRAINT FK__MedicalHi__Patie__3C69FB99 FOREIGN KEY (PatientId) REFERENCES Patients (PESEL),
    CONSTRAINT FK__MedicalHi__Event__3D5E1FD2 FOREIGN KEY (EventType) REFERENCES EventsTypes (EventTypeId)
);
```

### Tabela Medicines
```sql
CREATE TABLE Medicines
(
    EAN BIGINT PRIMARY KEY NOT NULL,
    Name NVARCHAR(100),
    CommonName NVARCHAR(100),
    Potency VARCHAR(100),
    Description NVARCHAR(100),
    Validity NVARCHAR(15),
    ProcedureType NVARCHAR(20),
    AuthorizationNr VARCHAR(10),
    ATC VARCHAR(15),
    Manufacturer NVARCHAR(100),
    Package NVARCHAR(100),
    Type VARCHAR(5),
    RefundValue FLOAT
);
CREATE UNIQUE INDEX Medicines_EAN_uindex ON Medicines (EAN);
```

### Tabela OrderDetails
```sql
CREATE TABLE OrderDetails
(
    OrderId INT NOT NULL,
    MedicineId BIGINT NOT NULL,
    UnitPrice INT NOT NULL,
    Quantity INT NOT NULL,
    CONSTRAINT PK__OrderDet__D7624946D19FFED2 PRIMARY KEY (OrderId, MedicineId),
    CONSTRAINT FK__OrderDeta__Order__45BE5BA9 FOREIGN KEY (OrderId) REFERENCES Orders (OrderId),
    CONSTRAINT OrderDetails_Medicines_EAN_fk FOREIGN KEY (MedicineId) REFERENCES Medicines (EAN)
);
```
### Tabela Orders
```sql
CREATE TABLE Orders
(
    OrderId INT PRIMARY KEY NOT NULL IDENTITY,
    WholesaleId INT,
    PharmacyId INT,
    OrderDate DATE NOT NULL,
    CONSTRAINT Orders_Wholesales_Id_fk FOREIGN KEY (WholesaleId) REFERENCES Wholesales (Id),
    CONSTRAINT Orders_Pharmacies_Id_fk FOREIGN KEY (PharmacyId) REFERENCES Pharmacies (Id)
);
```
