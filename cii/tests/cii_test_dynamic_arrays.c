typedef struct CII_DArray *CII_DArray_T;

// source
// CII P177
// note that size parameter is needed to give the caller the 
// flexibility to use its own types
// total size in memory is length * size;
extern CII_DArray_T CII_DArray_New(int length, int size);

extern void CII_DArray_Free(CII_DArray_T *arr);

extern int CII_DArray_Length(CII_DArray_T *arr);

extern int CII_DArray_Size(CII_DArray_T *arr);

// return a pointer to the index-th element if successful
extern void *CII_DArray_Get(CII_DArray_T *arr, int index);
// also return a pointer to the element but not the previous one
extern void *CII_DArray_Set(CII_DArray_T *arr, int index, void *elem);

// P178
// note that reize() invalidates any values returned by previous
// calls to Get()
extern void CII_DArray_Resize(CII_DArray_T *arr, int length);
// copy doesn't invalidate; it has the same default-initer behavior
extern CII_DArray_T *CII_DArray_Copy(CII_DArray_T *arr, int length);

// P179
// ArrayRep reveals that DArray is represented by a pointer to a 
// descriptor (holding the length, element-size parameters etc...)

int main() {
    return 0;
}
