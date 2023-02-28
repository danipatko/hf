# hf

| Homework                                                                                                                                                                                                            | Source file                                                                                  |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------- |
| [Mester > Haladó > Mohó > 5. Autó](https://github.com/asztrikx/mester-linux/blob/master/Halad%C3%B3/Moh%C3%B3%20algoritmusok/5.%20Aut%C3%B3%20*/feladat.pdf)                                                        | [moho_auto.cpp](./mester-moho-auto/moho_auto/moho_auto.cpp)                                  |
| [Mester > Haladó > Mohó > 9. Fénykép](https://github.com/asztrikx/mester-linux/blob/master/Halad%C3%B3/Moh%C3%B3%20algoritmusok/9.%20F%C3%A9nyk%C3%A9p%20**/feladat.pdf)                                            | [mester-moho-fenykep.cpp](./mester-moho-fenykep/mester-moho-fenykep/mester-moho-fenykep.cpp) |
| [Mester > Haladó > Mohó > 69. Jelzőlámpák](https://github.com/asztrikx/mester-linux/blob/master/Halad%C3%B3/Moh%C3%B3%20algoritmusok/69.%20Jelz%C5%91l%C3%A1mp%C3%A1k/feladat.pdf)                                  | [mester-jelzolampak.cpp](./mester-jelzolampak/mester-jelzolampak/mester-jelzolampak.cpp)     |
| [Mester > Haladó > Visszalépéses keresés > 13. Tehenészet](https://github.com/asztrikx/mester-linux/blob/master/Halad%C3%B3/Visszal%C3%A9p%C3%A9ses%20keres%C3%A9s/13.%20Tehen%C3%A9szet/feladat.pdf)               | [teheneszetek.cpp](./teheneszetek/teheneszetek.cpp)                                          |
| [Mester > Haladó > Visszalépses keresés > 17. Iskolaválasztás](https://github.com/asztrikx/mester-linux/blob/master/Halad%C3%B3/Visszal%C3%A9p%C3%A9ses%20keres%C3%A9s/17.%20Iskolav%C3%A1laszt%C3%A1s/feladat.pdf) | [iskolavalasztas.cpp](./iskolavalasztas/iskolavalasztas.cpp)                                 |
| N vezér rekurzívan                                                                                                                                                                                                  | [nqueen.cpp](./nqueen/nqueen.cpp)                                                            |
| Páros munka nem rekurzívan                                                                                                                                                                                          | [pairwork.cpp](./pairwork/pairwork.cpp)                                                      |
| [Access > Családfa](https://github.com/MolnAtt/SQL/tree/main/feladatsorok/Csaladfa)                                                                                                                                 | [csaladfa.accdbsaved.sql](./access/csaladfa.accdbsaved.sql)                                  |

### mester.sh

Simple bash script to automate running mester inputs.

Usage:

```sh
mester.sh [SOURCE].cpp [INPUT]
```

### SQLExport.bas

(literally) Basic macro to dump SQL queries from access databases.

Usage:

-   Open desired `.accdb` file, you may need to [unblock](https://support.microsoft.com/en-gb/topic/a-potentially-dangerous-macro-has-been-blocked-0952faa0-37e7-4316-b61d-5b5ed6024216) macros (in explorer > right click > properties > check unblock)
-   Go to **Database tools** tab and click **Macros**. This will open the VBA editor
-   **Select File** > **Import file** _(CTRL + M)_, choose `SQLExport.bas` included in repo
-   Save macro to project _(CTRL + S)_
-   Run with _(F5)_, select `Export` then click **run**

A messagebox should confirm that the queries have been saved to a `<path-to-file>.accdbsaved.sql` file.
