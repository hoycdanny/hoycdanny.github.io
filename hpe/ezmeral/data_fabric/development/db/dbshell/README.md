# Mapr dbshell

```shell=
[root@datafabric01 ~]# mapr dbshell
====================================================
*                  MapR-DB Shell                   *
* NOTE: This is a shell for JSON table operations. *
====================================================
Version: 6.2.0.0-mapr

MapR-DB Shell
maprdb root:> list /table
/table/test-table
1 table(s) found.

maprdb root:> help
* ! - Allows execution of operating system (OS) commands
* // - Inline comment markers (start of line only)
* ; - Inline comment markers (start of line only)
* cat - Print the content of the specified file on the standard output
* cd - Change the current directory to the specified path.
* clear - Clears the console
* cls - Clears the console
* create - Create a json table at the given path.
* date - Displays the local date and time
* debug - Sets/shows the debug mode.
* delete - Delete a document from the table.
* desc - Describes the properties of a table.
* drop - Deletes a MapR-DB json table.
* exists - Returns true if the table exists.
* exit - Exits the shell
* find - Retrieves one or more documents from the table.
* findbyid - Retrieves a single document from the table.
* help - List all commands usage
* indexlist - Retrieves the list of indexes for the specified table.
* indexscan - Scan the index and return the document in their natural order.
* insert - Inserts or replaces a document into the table.
* jsonoptions - Sets/shows the Json output options.
* list - Lists all tables in a folder or matching the specified pattern.
* ls - Lists files and folders.
* mkdir - Create a directory at the specified path.
* pwd - Print the absolute path of the current working directory.
* quit - Exits the shell
* replace - Replace a document based on condition.
* script - Parses the specified resource file and executes its commands
* system properties - Shows the shell's properties
* tableoptions - Sets/shows the MapR-DB Table access options.
* update - Update field in a single document.
* version - Displays shell version
* whoami - Prints the current MapR-DB Shell user.
```
