#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
/// the way to compile these kind of files 

//g++ mysql.cpp -o mysql -L/usr/include/mysql -lmysqlclient ;./mysql


int main(int argc, char **argv)
{
  MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }

  if (mysql_real_connect(con, "localhost", "root", "sniper2000",
          NULL, 0, NULL, 0) == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }

  if (mysql_query(con, "SHOW DATABASES"))
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }
  


  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL)
  {
      fprintf(stderr,"%s\n",mysql_error(con));
      mysql_close(con);
      exit(1);
  }

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;

  while ((row = mysql_fetch_row(result)))
  {
      for(int i = 0; i < num_fields; i++)
      {
          std::cout << row[i] << std::endl;
      }

  }

  mysql_free_result(result);
  mysql_close(con);

  exit(0);
}
