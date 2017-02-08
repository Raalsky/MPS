# Medical Prescriptions System

Główną ideą stojącą za **Medical Prescriptions System** było zaprojektowanie i zaimplementowanie systemu służącego do usprawnienia pracy placówek leczniczych i całego procesu leczenia od diagnozy przez wystawienie recepty po uzyskanie leków w możliwie najkrótszym czasie i najniższej cenie. W projekcie można wyróżnić trzy główne składowe. Pierwszą z nich jest obsługa zamówień w hurtownii i kontrola stanu i cen produktów. Podobna funkcjonalność została przygotowana do obsługi aptek i punktów aptecznych. Głównym elementem pozostaje mechanizm obsługi pacjentów, prowadzenia placówek leczniczych, koordynacja lekarzami i wystawianie recept leków.

W trakcie tworzenia bazy korzystaliśmy z ogólnodostępnych **rzeczywistych** danych pobranych z portalu: https://danepubliczne.gov.pl
Na dane te składają się:
- Lista leków
- Kwoty refundacji leków za rok 2016
- Lista hurtownii produktów medycznych
- Lista placówek leczniczych

Większość danych została przefiltrowana w celu usunięcia wpisów z niepełnymi danymi i ograniczona głównie do miasta Kraków.

## Autorzy
* Łukasz Kowalski ([@luke9642](https://github.com/luke9642))
* Rafał Jankowski ([@raalsky](https://github.com/raalsky))

# Diagram
![Database Diagram](diagram.png)

# Kod SQL
## Tabele (20)
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

## Procedury
### Procedura __AddUser
```sql
CREATE PROCEDURE __AddUser
(
  @Login NVARCHAR(25),
  @Password NVARCHAR(25),
  @PESEL CHAR(11),
  @GroupNr INT,
  @UserName NVARCHAR(25),
  @UserLastName NVARCHAR(25),
  @Birth DATE,
  @PostalCode CHAR(6),
  @Province NVARCHAR(25),
  @City NVARCHAR(25),
  @Prefix NVARCHAR(3),
  @Street NVARCHAR(25),
  @HouseNr VARCHAR(5),
  @FlatNr VARCHAR(5)
)
AS
BEGIN
    BEGIN TRANSACTION [UserCreation];
    BEGIN TRY
      IF dbo.CheckPESEL(@PESEL) = 0
      BEGIN
        RAISERROR ('Niepoprawny PESEL', 16,34)
        ROLLBACK TRANSACTION [UserCreation];
      END
      IF dbo.isAlphaNumerical(@Login) = 0
      BEGIN
        RAISERROR('Login może zawierać wyłącznie litery i cyfry',16,36);
        ROLLBACK TRANSACTION [UserCreation];
      END
      IF EXISTS (SELECT Login FROM Users WHERE Login = @Login)
      BEGIN
        RAISERROR('Istnieje już podany login',16,35);
        ROLLBACK TRANSACTION [UserCreation];
      END
      IF NOT EXISTS (SELECT PostalCode FROM Adresses WHERE PostalCode = @PostalCode)
        INSERT INTO Adresses (PostalCode, Province, City) VALUES (@PostalCode, @Province, @City);
      INSERT INTO Users (Login, Password, PESEL, GroupNr, UserName, UserLastName, Birth, PostalCode, Prefix, Street, HouseNr, FlatNr)
          VALUES (@Login, HASHBYTES('md5',@Password), @PESEL, @GroupNr, @UserName, @UserLastName, @Birth, @PostalCode, @Prefix, @Street, @HouseNr, @FlatNr)
      COMMIT TRANSACTION [UserCreation];
    END TRY
    BEGIN CATCH
      SELECT ERROR_MESSAGE() AS ErrorMessage;
      ROLLBACK TRANSACTION [UserCreation];
    END CATCH
END
```
Przykład:
```sql
__AddUser 'anowak2@','annanowak123','96042108611',2,'Anna','Nowak','1996-03-22','32-330','małopolskie','Kraków','ul.','Marszałkowska','7B','6'
```

### Procedura AddDoctor
```sql
CREATE PROCEDURE AddDoctor(
  @InstitutionId INT,
  @Branch NVARCHAR(25),
  @Login NVARCHAR(25),
  @Password NVARCHAR(25),
  @PESEL CHAR(11),
  @GroupNr INT,
  @UserName NVARCHAR(25),
  @UserLastName NVARCHAR(25),
  @Birth DATE,
  @PostalCode CHAR(6),
  @Province NVARCHAR(25),
  @City NVARCHAR(25),
  @Prefix NVARCHAR(3),
  @Street NVARCHAR(25),
  @HouseNr VARCHAR(5),
  @FlatNr VARCHAR(5)
)
  AS
BEGIN
  BEGIN TRANSACTION [DoctorCreation];
  BEGIN TRY
    IF NOT EXISTS(SELECT InstitutionId FROM Institutions WHERE InstitutionId = @InstitutionId)
      BEGIN
        RAISERROR('Nie ma takiej instytucji',16,34);
        ROLLBACK TRANSACTION [DoctorCreation];
      END
    ELSE
    EXEC __AddUser @Login,@Password,@PESEL,@GroupNr,@UserName,@UserLastName,@Birth,@PostalCode,@Province,@City,@Prefix,@Street,@HouseNr,@FlatNr
    DECLARE @UserId INT
    SET @UserId = (SELECT UserId FROM Users WHERE Login = @Login)
    INSERT INTO Doctors (UserId, InstitutionId, Branch, EmploymentDate) VALUES (@UserId, @InstitutionId, @Branch, GETDATE());
    COMMIT TRANSACTION [DoctorCreation];
  END TRY
  BEGIN CATCH
    RAISERROR('Błąd podczas tworzenia lekarza',16,1);
    ROLLBACK TRANSACTION [DoctorCreation];
  END CATCH
END
```

### Procedura AddPatient
```sql
CREATE PROCEDURE AddPatient(
  @PESEL CHAR(11),
  @PatientName VARCHAR(25),
  @PatientLastName VARCHAR(25),
  @Birth DATE,
  @PostalCode CHAR(6),
  @Province NVARCHAR(25),
  @City NVARCHAR(25),
  @Prefix NVARCHAR(3),
  @Street NVARCHAR(25),
  @HouseNr VARCHAR(5),
  @FlatNr VARCHAR(5),
  @BloodType NVARCHAR(5)
)
  AS
BEGIN
  BEGIN TRANSACTION [PatientCreation];
  BEGIN TRY
    IF dbo.CheckPESEL(@PESEL) = 0
      BEGIN
        RAISERROR ('Zły PESEL', 16,34);
        ROLLBACK TRANSACTION [UserCreation];
      END
    ELSE
    IF NOT EXISTS (SELECT PostalCode FROM Adresses WHERE PostalCode = @PostalCode)
      INSERT INTO Adresses (PostalCode, Province, City) VALUES (@PostalCode, @Province, @City);
    INSERT INTO Patients (PESEL, PatientName, PatientLastName, Birth, PostalCode, Prefix, Street, HouseNr, FlatNr, BloodType)
    VALUES (@PESEL, @PatientName, @PatientLastName, @Birth, @PostalCode, @Prefix, @Street, @HouseNr, @FlatNr, @BloodType);
    COMMIT TRANSACTION [PatientCreation];
  END TRY
  BEGIN CATCH
    RAISERROR ('Błąd podczas tworzenia pacjenta', 16,1);
    ROLLBACK TRANSACTION [PatientCreation];
  END CATCH
END
```

### Procedura AddInstitution
```sql
CREATE PROCEDURE AddInstitution
(
  @InstitutionName NVARCHAR(50),
  @PostalCode CHAR(6),
  @Province NVARCHAR(25),
  @City NVARCHAR(25),
  @Prefix NVARCHAR(3),
  @Street NVARCHAR(25),
  @HouseNr VARCHAR(5)
)
AS
BEGIN
    BEGIN TRANSACTION [InstitutionCreation];
    BEGIN TRY
      IF NOT EXISTS (SELECT PostalCode FROM Adresses WHERE PostalCode = @PostalCode)
        INSERT INTO Adresses (PostalCode, Province, City) VALUES (@PostalCode, @Province, @City);
      INSERT INTO Institutions (InstitutionName, PostalCode, Prefix, Street, HouseNr)
          VALUES (@InstitutionName, @PostalCode, @Prefix, @Street, @HouseNr)
      COMMIT TRANSACTION [InstitutionCreation];
    END TRY
    BEGIN CATCH
      RAISERROR ('Błąd podczas tworzenia instytucji', 16,1);
      ROLLBACK TRANSACTION [InstitutionCreation];
    END CATCH
END
```

### Procedura AddPharmacy
```sql
CREATE PROCEDURE AddPharmacy
(
  @Name NVARCHAR(50),
  @Type NVARCHAR(30),
  @AuthorizationNr VARCHAR(40),
  @PostalCode CHAR(6),
  @Province NVARCHAR(25),
  @City NVARCHAR(25),
  @Prefix NVARCHAR(3),
  @Street NVARCHAR(25),
  @HouseNr VARCHAR(5),
  @FlatNr VARCHAR(5)
)
AS
BEGIN
    BEGIN TRANSACTION [PharmacyCreation];
    BEGIN TRY
      IF NOT EXISTS (SELECT PostalCode FROM Adresses WHERE PostalCode = @PostalCode)
        INSERT INTO Adresses (PostalCode, Province, City) VALUES (@PostalCode, @Province, @City);
      INSERT INTO Pharmacies (Name, Type, AuthorizationNr, PostalCode, Prefix, Street, HouseNr, FlatNr)
          VALUES (@Name, @Type, @AuthorizationNr, @PostalCode, @Prefix, @Street, @HouseNr, @FlatNr)
      COMMIT TRANSACTION [PharmacyCreation];
    END TRY
    BEGIN CATCH
      RAISERROR ('Błąd podczas tworzenia apteki', 16,1);
      ROLLBACK TRANSACTION [PharmacyCreation];
    END CATCH
END
```

### Procedura AddWholesale
```sql
CREATE PROCEDURE AddWholesale
(
  @WholesaleName NVARCHAR(50),
  @AuthorizationNr VARCHAR(40),
  @PostalCode CHAR(6),
  @Province NVARCHAR(25),
  @City NVARCHAR(25),
  @Prefix NVARCHAR(3),
  @Street NVARCHAR(25),
  @HouseNr VARCHAR(5)
)
AS
BEGIN
    BEGIN TRANSACTION [WholesaleCreation];
    BEGIN TRY
      IF NOT EXISTS (SELECT PostalCode FROM Adresses WHERE PostalCode = @PostalCode)
        INSERT INTO Adresses (PostalCode, Province, City) VALUES (@PostalCode, @Province, @City);
      INSERT INTO Wholesales (WholesaleName, AuthorizationNr, CreationDate, PostalCode, Prefix, Street, HouseNr)
          VALUES (@WholesaleName, @AuthorizationNr, GETDATE(), @PostalCode, @Prefix, @Street, @HouseNr)
      COMMIT TRANSACTION [WholesaleCreation];
    END TRY
    BEGIN CATCH
      RAISERROR ('Błąd podczas tworzenia hurtowni', 16,1);
      ROLLBACK TRANSACTION [WholesaleCreation];
    END CATCH
END
```

### AddPharmacist
```sql
CREATE PROCEDURE AddPharmacist(
  @PharmacyId INT,
  @Login NVARCHAR(25),
  @Password NVARCHAR(25),
  @PESEL CHAR(11),
  @GroupNr INT,
  @UserName NVARCHAR(25),
  @UserLastName NVARCHAR(25),
  @Birth DATE,
  @PostalCode CHAR(6),
  @Province NVARCHAR(25),
  @City NVARCHAR(25),
  @Prefix NVARCHAR(3),
  @Street NVARCHAR(25),
  @HouseNr VARCHAR(5),
  @FlatNr VARCHAR(5)
)
  AS
BEGIN
  BEGIN TRANSACTION [PharmacistCreation];
  BEGIN TRY
    IF NOT EXISTS(SELECT Id FROM Pharmacies WHERE Id = @PharmacyId)
      BEGIN
        RAISERROR('Nie ma takiej apteki',16,34);
        ROLLBACK TRANSACTION [PharmacistCreation];
      END
    ELSE
    EXEC __AddUser @Login,@Password,@PESEL,@GroupNr,@UserName,@UserLastName,@Birth,@PostalCode,@Province,@City,@Prefix,@Street,@HouseNr,@FlatNr
    DECLARE @UserId INT
    SET @UserId = (SELECT UserId FROM Users WHERE Login = @Login)
    INSERT INTO Pharmacists (UserId, PharmacyId, EmploymentDate) VALUES (@UserId, @PharmacyId, GETDATE());
    COMMIT TRANSACTION [PharmacistCreation];
  END TRY
  BEGIN CATCH
    RAISERROR('Błąd podczas tworzenia farmaceuty',16,1);
    ROLLBACK TRANSACTION [PharmacistCreation];
  END CATCH
END
```

### Procedura AddSaler
```sql
CREATE PROCEDURE AddSaler(
  @WholesaleId INT,
  @Login NVARCHAR(25),
  @Password NVARCHAR(25),
  @PESEL CHAR(11),
  @GroupNr INT,
  @UserName NVARCHAR(25),
  @UserLastName NVARCHAR(25),
  @Birth DATE,
  @PostalCode CHAR(6),
  @Province NVARCHAR(25),
  @City NVARCHAR(25),
  @Prefix NVARCHAR(3),
  @Street NVARCHAR(25),
  @HouseNr VARCHAR(5),
  @FlatNr VARCHAR(5)
)
  AS
BEGIN
  BEGIN TRANSACTION [SalerCreation];
  BEGIN TRY
    IF NOT EXISTS(SELECT Id FROM Wholesales WHERE Id = @WholesaleId)
      BEGIN
        RAISERROR('Nie ma takiej hurtowni',16,34);
        ROLLBACK TRANSACTION [SalerCreation];
      END
    ELSE
    EXEC __AddUser @Login,@Password,@PESEL,@GroupNr,@UserName,@UserLastName,@Birth,@PostalCode,@Province,@City,@Prefix,@Street,@HouseNr,@FlatNr
    DECLARE @UserId INT
    SET @UserId = (SELECT UserId FROM Users WHERE Login = @Login)
    INSERT INTO Salers (UserId, WholesaleId, EmploymentDate) VALUES (@UserId, @WholesaleId, GETDATE());
    COMMIT TRANSACTION [SalerCreation];
  END TRY
  BEGIN CATCH
    RAISERROR('Błąd podczas tworzenia pracownika hurtowni',16,1);
    ROLLBACK TRANSACTION [SalerCreation];
  END CATCH
END
```

### Procedura GetHistory
```sql
CREATE PROCEDURE GetHistory(@PESEL CHAR(11))
AS
BEGIN
  SELECT ET.EventName, MEET.EventBegin, MEET.EventEnd, MEET.Description FROM EventsTypes ET JOIN
  (SELECT ME.* FROM Patients P JOIN MedicalEvents ME
    ON P.PESEL = ME.PatientId
    WHERE P.PESEL = @PESEL) AS MEET
  ON ET.EventTypeId = MEET.EventType
END
```

### Procedura AddOrder
```sql
USE mps;
GO
IF OBJECT_ID ( 'AddOrder', 'P' ) IS NOT NULL
    DROP PROCEDURE AddOrder;
GO
CREATE PROCEDURE AddOrder
(
  @WholesaleId INT,
  @PharmacyId INT,
  @Items VARCHAR(1000)
)
AS
BEGIN
  BEGIN TRANSACTION [AddOrder];
  BEGIN TRY
    IF NOT EXISTS(SELECT Id FROM Pharmacies WHERE Id = @PharmacyId)
      RAISERROR('Podana apteka nie istnieje',16,60)
    IF NOT EXISTS(SELECT Id FROM Wholesales WHERE Id = @WholesaleId)
      RAISERROR('Podana hurtownia nie istnieje',16,61)

    INSERT INTO Orders (WholesaleId, PharmacyId, OrderDate) VALUES (@WholesaleId, @PharmacyId, GETDATE())

    DECLARE @OrderId INT = SCOPE_IDENTITY()

    DECLARE @individual varchar(50) = null
    DECLARE @EAN BIGINT
    DECLARE @Quantity INT
    DECLARE @products VARCHAR(1000) = @Items
    DECLARE @UnitPrice FLOAT;

    WHILE LEN(@products) > 0
    BEGIN
      IF PATINDEX('%,%', @products) > 0
      BEGIN
        SET @individual = SUBSTRING(@products, 0, PATINDEX('%,%', @products))
        SET @EAN = CONVERT(BIGINT,SUBSTRING(@individual, 0, CHARINDEX('[', @individual)))
        SET @Quantity = CONVERT(INT,SUBSTRING(@individual, LEN(@EAN) + 2, CHARINDEX(']',@individual) - LEN(@EAN) - 2))
        ---SELECT @individual, @EAN, @Quantity

        IF NOT EXISTS(SELECT EAN FROM Medicines WHERE EAN = @EAN)
          RAISERROR('Podany lek nie istnieje',16,62)

        IF NOT EXISTS(SELECT Price FROM WholesalesProducts WHERE MedicineId = @EAN)
          RAISERROR('Podana hurtownia nie dysponuje aktualnie danym lekiem',16,63)

        SELECT @UnitPrice = Price FROM WholesalesProducts WHERE MedicineId = @EAN

        INSERT INTO OrderDetails (OrderId, MedicineId, UnitPrice, Quantity) VALUES (@OrderId, @EAN, @UnitPrice, @Quantity)
        SET @products = SUBSTRING(@products, LEN(@individual + ',') + 1, LEN(@products))
      END
      ELSE
      BEGIN
        SET @individual = @products
        SET @products = NULL
        SET @EAN = CONVERT(BIGINT,SUBSTRING(@individual, 0, CHARINDEX('[', @individual)))
        SET @Quantity = CONVERT(INT,SUBSTRING(@individual, LEN(@EAN) + 2, CHARINDEX(']',@individual) - LEN(@EAN) - 2))
        ---SELECT @individual, @EAN, @Quantity
        IF NOT EXISTS(SELECT EAN FROM Medicines WHERE EAN = @EAN)
          RAISERROR('Podany lek nie istnieje',16,62)

        IF NOT EXISTS(SELECT Price FROM WholesalesProducts WHERE MedicineId = @EAN)
          RAISERROR('Podana hurtownia nie dysponuje aktualnie danym lekiem',16,63)

        SELECT @UnitPrice = Price FROM WholesalesProducts WHERE MedicineId = @EAN

        INSERT INTO OrderDetails (OrderId, MedicineId, UnitPrice, Quantity) VALUES (@OrderId, @EAN, @UnitPrice, @Quantity)
      END
  END
  COMMIT TRANSACTION [AddOrder];
  END TRY
  BEGIN CATCH
    SELECT ERROR_MESSAGE() AS ErrorMessage
    ROLLBACK TRANSACTION [AddOrder];
  END CATCH
END
```
Przykład:
```sql
AddOrder 2, 92, '5055565711958[4],4037353010604[12],4037353010604[1]'
```

### Procedura AddWholesaleProduct
```sql
USE mps;
GO
IF OBJECT_ID ( 'AddWholesaleProduct', 'P' ) IS NOT NULL
    DROP PROCEDURE AddWholesaleProduct;
GO
CREATE PROCEDURE AddWholesaleProduct
(
  @WholesaleId INT,
  @MedicineId BIGINT,
  @Price FLOAT
)
AS
BEGIN
  BEGIN TRY
    IF @Price < 0
      RAISERROR ('Cena nie może być ujemna',16,50)
    IF NOT EXISTS(SELECT * FROM Wholesales WHERE Id = @WholesaleId)
      RAISERROR ('Podana hurtownia nie istnieje',16,51)
    IF NOT EXISTS(SELECT * FROM Medicines WHERE EAN = @MedicineId)
      RAISERROR ('Podany lek nie istnieje',16,52)
    IF EXISTS(SELECT * FROM WholesalesProducts WHERE WholesaleId = @WholesaleId AND MedicineId = @MedicineId)
      UPDATE WholesalesProducts SET Price = @Price WHERE WholesaleId = @WholesaleId AND MedicineId = @MedicineId
    ELSE
      INSERT INTO WholesalesProducts (MedicineId, WholesaleId, Price) VALUES (@MedicineId, @WholesaleId, @Price)
  END TRY
  BEGIN CATCH
    SELECT ERROR_MESSAGE() AS ErrorMessage
  END CATCH
END
```

### Procedura AddPharmacyProduct
```sql
USE mps;
GO
IF OBJECT_ID ( 'AddPharmacyProduct', 'P' ) IS NOT NULL
    DROP PROCEDURE AddPharmacyProduct;
GO
CREATE PROCEDURE AddPharmacyProduct
(
  @PharmacyId INT,
  @MedicineId BIGINT,
  @Price FLOAT
)
AS
BEGIN
  BEGIN TRY
    IF @Price < 0
      RAISERROR ('Cena nie może być ujemna',16,50)
    IF NOT EXISTS(SELECT * FROM Pharmacies WHERE Id = @PharmacyId)
      RAISERROR ('Podana apteka nie istnieje',16,51)
    IF NOT EXISTS(SELECT * FROM Medicines WHERE EAN = @MedicineId)
      RAISERROR ('Podany lek nie istnieje',16,52)
    IF EXISTS(SELECT * FROM PharmaciesProducts WHERE PharmacyId = @PharmacyId AND MedicineId = @MedicineId)
      UPDATE PharmaciesProducts SET Price = @Price WHERE PharmacyId = @PharmacyId AND MedicineId = @MedicineId
    ELSE
      INSERT INTO PharmaciesProducts (MedicineId, PharmacyId, Price) VALUES (@MedicineId, @PharmacyId, @Price)
  END TRY
  BEGIN CATCH
    SELECT ERROR_MESSAGE() AS ErrorMessage
  END CATCH
END
```
