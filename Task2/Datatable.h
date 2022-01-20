
#define MAXELEMENTS 1000
#define MAXSTRING 63
#define MAXCOL 6


 struct Datatable
{
    char scols[MAXELEMENTS][3][MAXSTRING];
    double floatcols[MAXELEMENTS][3];
    char colnames[MAXCOL][MAXSTRING];
    int rowcounter;

}dt, s;



/*Declaration of functions */
struct Datatable* initDT(struct Datatable *DT);


void deinitDT(struct Datatable *DT);


void loadDT(char *file, struct Datatable *DT);


void exportDT(char *file, struct Datatable *DT);


void showDT(struct Datatable *DT);


struct Datatable projectDT (struct Datatable *DT,struct Datatable *tablecopy, int x , int y, int m, int n);


void mutateDT(struct Datatable *DT, int num);

