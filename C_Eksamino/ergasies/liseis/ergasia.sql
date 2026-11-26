
SET SERVEROUTPUT ON;

DECLARE
    num1 NUMBER;
    num2 NUMBER;
    total NUMBER;
BEGIN
    num1 := 10;
    num2 := 20;
    total := num1 + num2;
    DBMS_OUTPUT.PUT_LINE('The sum is: ' || total);
END;
/