# processCSV
IN DEVELOPMENT: Processing CSV files, through reading the entire content in memory then use it (NOT THE RIGHT WAY TO PROCESS LARGE FILES)

CSV processor is not an easy work. See Wikipedia for details: (credit: Wikipedia.org) "The CSV file format is not fully standardized. The basic idea of separating fields with a comma is clear, but the situation gets complicated when field data also contain commas or embedded line breaks. CSV implementations may not handle such field data, or they may use quotation marks to surround the field. Quotation does not solve everything: some fields may need embedded quotation marks, so a CSV implementation may include escape characters or escape sequences." 

In my work I need the following CSV-Model:
Separator = ;
TextQualifier = "
EscapeCharacter = \
EscapeSequences = "\r\n\t\"" and there is no real line break inside the data // see C Standard
Separator always at the end of the line (last data must be an empty string)
With or without header
The header containing field names does contain unqualified text (no " in header) and only valid field names
Starting row can be other than the first one
NO comments, removed lines nor blocks
NO row count limit (the string is parsed, line-by-line and NOT loaded entirely in memory)

This is my creation - not complete - the next project will contain ...
