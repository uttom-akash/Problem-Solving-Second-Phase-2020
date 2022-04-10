-- BEGIN DATA PREPARATION
CREATE TABLE #tempindextable
(
     id           INT IDENTITY,
     tablename	  VARCHAR(200),
	 dropindexname VARCHAR(200)
);
​
WITH indexcoltable AS 
	(SELECT Object_name(IndexTab.object_id) AS TableName,
                IndexTab.index_id              AS IndexId,
                IndexTab.NAME                  AS IndexName,
                (SELECT Col_name(IndexTab.object_id, column_id) AS [data()]
                 FROM   sys.index_columns AS IndexColumns
                 WHERE  IndexColumns.object_id = IndexTab.object_id
                        AND IndexColumns.index_id = IndexTab.index_id
                 FOR xml path(''))              AS allcolumnsNames
         
		 FROM   sys.indexes AS IndexTab
         WHERE  Object_schema_name(IndexTab.object_id) != 'sys')
INSERT INTO #tempindextable 
SELECT withIndexCol1.tablename as tablename,
		case
			when SUBSTRING(withIndexCol1.indexname,1,2)='PK' then withindexCol2.indexname
			when SUBSTRING(withIndexCol1.indexname,1,2)='nci' then withIndexCol1.indexname
			when Reverse(Parsename(Replace(Reverse(withIndexCol1.indexname), '_', '.'), 2)) != withIndexCol1.tablename then withIndexCol1.indexname
			else withIndexCol2.indexname
		end as dropindexname
FROM   indexcoltable AS withIndexCol1
INNER JOIN indexcoltable AS withindexCol2
      ON withIndexCol1.tablename = withindexCol2.tablename
      AND withIndexCol1.indexid < withindexCol2.indexid
      AND withIndexCol1.allcolumnsNames = withindexCol2.allcolumnsNames;

-- END DATA PREPARATION


-- BEGIN DATA MANIPULATION
DECLARE @totalindex INT;
DECLARE @dropindex VARCHAR(200);
DECLARE @tablename VARCHAR(200);
DECLARE @counter INT = 1;
SELECT @totalindex = Count(*)
FROM   #tempindextable;
​
​
WHILE ( @Counter <= @totalIndex )
      BEGIN
          SELECT @tablename = temp.tablename,@dropindex = temp.dropindexname
          FROM   #tempindextable AS temp
          WHERE  temp.id = @Counter;
​
          PRINT 'dropping from table: ' + @tablename + ' index:' + @dropindex;
          -- need to uncomment to rename index
		  DECLARE @SQL NVARCHAR(MAX) = 'DROP INDEX ' + @tablename + '.' + @dropindex;
		  EXEC sp_executesql @SQL;
          
		  SET @Counter = @Counter + 1;
      END

IF Object_id(N'tempdb..#TempIndexTable') IS NOT NULL
  BEGIN
      DROP TABLE #tempindextable;
  END 

-- END DATA MANIPULATION