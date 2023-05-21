#include <CoreGraphics/CoreGraphics.h>
#include <stdio.h>

typedef int CGSConnectionID;
extern CGSConnectionID _CGSDefaultConnection(void);
extern CFArrayRef CGSCopyManagedDisplaySpaces(const CGSConnectionID cid);

static void printKV (const void* key, const void* value, void* context) {
    CFShow(key);
    CFShow(value);
}

int main() {
    #if 1
    CGSConnectionID cid = _CGSDefaultConnection();
    printf("connectionID: %d\n", cid);

    CFArrayRef displayList = CGSCopyManagedDisplaySpaces(cid);
    CFIndex displayCount = CFArrayGetCount(displayList);
    printf("Display Count: %ld\n", displayCount);

    printf("Spaces:\n");
    for (CFIndex i = 0; i < displayCount; i++) {
        CFDictionaryRef spaceDict = CFArrayGetValueAtIndex(displayList, i);
        CFDictionaryApplyFunction(spaceDict, printKV, NULL);
    }

    return 0;
    #else
    return 1;
    #endif
}

