8 entries are needed for a single-level linear page table.

Since pages are 8KB then offset can be within 0 and 8191. 
These numbers are 13 bits long. Then we have 3 more bits for specifying page number.
Page number can be within 0 and 7: number of pages is 8. We need 8 entries.