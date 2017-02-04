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

### Tabela Patients
```sql
CREATE TABLE Patients
(
    PESEL CHAR(11) PRIMARY KEY NOT NULL,
    PatientName VARCHAR(25) NOT NULL,
    PatientLastName VARCHAR(25) NOT NULL,
    Birth DATE NOT NULL,
    PostalCode CHAR(6) NOT NULL,
    Prefix NVARCHAR(3),
    Street NVARCHAR(25),
    HouseNr VARCHAR(5),
    FlatNr VARCHAR(5),
    BloodType NVARCHAR(5),
    CONSTRAINT Patients_Adresses_PostalCode_fk FOREIGN KEY (PostalCode) REFERENCES Adresses (PostalCode)
);
```

### Tabela Pharmacies
```sql
CREATE TABLE Pharmacies
(
    Id INT PRIMARY KEY NOT NULL IDENTITY,
    Name NVARCHAR(50) NOT NULL,
    Type NVARCHAR(30) NOT NULL,
    AuthorizationNr VARCHAR(40) NOT NULL,
    CreationDate DATE NOT NULL,
    AuthorizationDate DATE,
    PostalCode CHAR(6) NOT NULL,
    Prefix NVARCHAR(3),
    Street NVARCHAR(25),
    HouseNr VARCHAR(5),
    FlatNr VARCHAR(5),
    CONSTRAINT Pharmacies_Adresses_PostalCode_fk FOREIGN KEY (PostalCode) REFERENCES Adresses (PostalCode)
);
CREATE UNIQUE INDEX Pharmacies_Id_uindex ON Pharmacies (Id);
CREATE UNIQUE INDEX Pharmacies_AuthorizationNr_uindex ON Pharmacies (AuthorizationNr);
```

### Tabela PharmaciesProducts
```sql
CREATE TABLE PharmaciesProducts
(
    MedicineId BIGINT NOT NULL,
    PharmacyId INT NOT NULL,
    Price FLOAT NOT NULL,
    CONSTRAINT PK__Pharmaci__B4F8FA3A90C10BBB PRIMARY KEY (MedicineId, PharmacyId),
    CONSTRAINT PharmaciesProducts_Medicines_EAN_fk FOREIGN KEY (MedicineId) REFERENCES Medicines (EAN),
    CONSTRAINT PharmaciesProducts_Pharmacies_Id_fk FOREIGN KEY (PharmacyId) REFERENCES Pharmacies (Id)
);
```

### Tabela Pharmacists
```sql
CREATE TABLE Pharmacists
(
    UserId INT PRIMARY KEY NOT NULL,
    PharmacyId INT,
    EmploymentDate DATE NOT NULL,
    CONSTRAINT FK__Pharmacis__UserI__671F4F74 FOREIGN KEY (UserId) REFERENCES Users (UserId),
    CONSTRAINT Pharmacists_Pharmacies_Id_fk FOREIGN KEY (PharmacyId) REFERENCES Pharmacies (Id)
);
```

### Tabela PrescriptionDetails
```sql
CREATE TABLE PrescriptionDetails
(
    PrescriptionId INT NOT NULL,
    MedicineId BIGINT NOT NULL,
    Quantity INT DEFAULT 1 NOT NULL,
    Description NVARCHAR(100),
    CONSTRAINT PK__Prescrip__54E11ABBCAED791D PRIMARY KEY (PrescriptionId, MedicineId),
    CONSTRAINT FK__Prescript__Presc__4D5F7D71 FOREIGN KEY (PrescriptionId) REFERENCES Prescriptions (PrescriptionId),
    CONSTRAINT PrescriptionDetails_Medicines_EAN_fk FOREIGN KEY (MedicineId) REFERENCES Medicines (EAN)
);
```

### Tabela Prescriptions
```sql
CREATE TABLE Prescriptions
(
    PrescriptionId INT PRIMARY KEY NOT NULL IDENTITY,
    PatientId CHAR(11) NOT NULL,
    PrescriptionDate DATE NOT NULL,
    DoctorId INT NOT NULL,
    CONSTRAINT FK__Prescript__Patie__4316F928 FOREIGN KEY (PatientId) REFERENCES Patients (PESEL),
    CONSTRAINT FK__Prescript__Docto__619B8048 FOREIGN KEY (DoctorId) REFERENCES Doctors (UserId)
);
```

### Tabela Salers
```sql
CREATE TABLE Salers
(
    UserId INT PRIMARY KEY NOT NULL,
    WholesaleId INT,
    EmploymentDate DATE NOT NULL,
    CONSTRAINT FK__Salers__UserId__634EBE90 FOREIGN KEY (UserId) REFERENCES Users (UserId),
    CONSTRAINT Salers_Wholesales_Id_fk FOREIGN KEY (WholesaleId) REFERENCES Wholesales (Id)
);
```

### Tabela Users
```sql
CREATE TABLE Users
(
    UserId INT PRIMARY KEY NOT NULL IDENTITY,
    Login NVARCHAR(25) NOT NULL,
    Password BINARY(16) NOT NULL,
    PESEL CHAR(11) NOT NULL,
    GroupNr INT NOT NULL,
    UserName NVARCHAR(25) NOT NULL,
    UserLastName NVARCHAR(25) NOT NULL,
    Birth DATE NOT NULL,
    PostalCode CHAR(6) NOT NULL,
    Prefix NVARCHAR(3),
    Street NVARCHAR(25),
    HouseNr VARCHAR(5),
    FlatNr VARCHAR(5),
    CONSTRAINT Users_Adresses_PostalCode_fk FOREIGN KEY (PostalCode) REFERENCES Adresses (PostalCode)
);
CREATE UNIQUE INDEX UQ__Users__5E55825B1C8A0ED9 ON Users (Login);
```

### Tabela Wholesales
```sql
CREATE TABLE Wholesales
(
    Id INT PRIMARY KEY NOT NULL IDENTITY,
    WholesaleName NVARCHAR(50) NOT NULL,
    AuthorizationNr VARCHAR(40) NOT NULL,
    CreationDate DATE,
    PostalCode CHAR(6) NOT NULL,
    Prefix NVARCHAR(3),
    Street NVARCHAR(25),
    HouseNr VARCHAR(5),
    CONSTRAINT Wholesales_Adresses_PostalCode_fk FOREIGN KEY (PostalCode) REFERENCES Adresses (PostalCode)
);
CREATE UNIQUE INDEX Wholesales_Id_uindex ON Wholesales (Id);
```

### Tabela WholesalesProducts
```sql
CREATE TABLE WholesalesProducts
(
    MedicineId BIGINT NOT NULL,
    WholesaleId INT NOT NULL,
    Price FLOAT NOT NULL,
    CONSTRAINT PK__Wholesal__D372E6CEC58D94DE PRIMARY KEY (MedicineId, WholesaleId),
    CONSTRAINT WholesalesProducts_Medicines_EAN_fk FOREIGN KEY (MedicineId) REFERENCES Medicines (EAN),
    CONSTRAINT WholesalesProducts_Wholesales_Id_fk FOREIGN KEY (WholesaleId) REFERENCES Wholesales (Id)
);
```
