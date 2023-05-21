# Just code to debug space IDs

Most of the symbols and signatures of CoreDisplay are not public
and that is probably where I need to look next to understand this..

# Compile
```sh
./comp
```

# Issue

This is potentially just normal behavior but it's logging an awful lot and I
can't corrolate the display ID to anything.
```sh
log stream --predicate 'subsystem == "com.apple.CoreDisplay"' --debug
```
results in:
```txt
WindowServer: (CoreDisplay) [com.apple.CoreDisplay:default] [DEBUG] - On display 0x04280f40
```

I can't see anything saved in NVRAM, tried a reset and my mac has always been
really weird with displays.

My suspiscion is that it's some sort of virtual display/space ("Displays have
their own spaces") and that one of my services is querying it repeatly causing
performance issues.

# Example output
```
connectionID: 221463
Display Count: 1
Spaces:
Current Space
{
    ManagedSpaceID = 3;
    id64 = 3;
    type = 0;
    uuid = "54PP8528-000N-4454-989O-B1C7O8782OQ5";
}
Spaces
<CFArray 0x600001814680 [0x7ff860a1fd70]>{type = immutable, count = 1, values = (
        0 : {
    ManagedSpaceID = 3;
    id64 = 3;
    type = 0;
    uuid = "54PP8528-R00N-4454-989O-O1P7B8782BD5";
}
)}
Display Identifier
81Q74PO8-3O2Q-1336-O484-9Q4119P5361R
```

