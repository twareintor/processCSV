# processCSV
IN DEVELOPMENT: Processing CSV files, through reading the entire content in memory then use it (NOT THE RIGHT WAY TO PROCESS LARGE FILES)

This is a trial to adapt a ready made code (not credited) which parses CSV string in main function line-by-line, in which line-breaks are considered inside the data cell if occurs before the text qualifier and separator.
In fact, any standard CSV parser must with this.
I don't know what it does when there are additional characters (e.g. spaces) between text qualifier and separator. Also when the text qualifier is escaped. Nor the escape character, if any.

