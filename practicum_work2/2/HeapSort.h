typedef struct
{
    int* arr;
    int  children;
    int  size;
    int  capacity;
} Heap;

Heap* HeapCtor(FILE* file, int capacity, int k);

void SiftDown(Heap* hp, int index);
void SiftUp(Heap* hp, int index);
void HeapInsert(Heap* hp, int data);
void HeapDtor(Heap* h);
void HeapSort(Heap* hp);


int GiveKChild(int index, int k, int mod);
int GetParent(int index, int k);
int GetMax(Heap* hp, int index);
int ExtractMax(Heap* h);

void HeapTester(const int from, const int to, const int step, const char* src_path, const char* out_folder, int children_number);
void HeapTesting(int children_num, const char* res_name, FILE* file_in, FILE* file_out, int size);
void HeapArrCtor(FILE* file, int* arr, int size);
