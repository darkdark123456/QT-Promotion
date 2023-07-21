package com.javaForcpp;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;
import java.util.concurrent.FutureTask;
import java.sql.ResultSet;

public class UserLogin {

    public static String DRIVER_NAME = "com.mysql.jdbc.Driver";
    public static String HOST = "jdbc:mysql://111.230.112.186:3306/usrinfo";
    public static String USER = "MENG";
    public static String PASSWD = "123456";

    public static Connection connection=null;
    public static Statement  statement=null;
    public static ResultSet  resultSet=null;

    public static String infoUsername;
    public static String infoPasswd;

    public static String getPasswd;
    public static String getUsername;

    public static String flag="0";

    public static String getConnectDatabase(String parm1,String parm2){
        Callable callable =new Callable() {
            @Override
            public String call() throws Exception {
                try {

                    String QtUsername=UserLogin.infoUsername;
                    String QtPasswd=UserLogin.infoPasswd;
                    String judgeUsernameExistenceSqlQuery=String.format("select * from userdata where username=%s",QtUsername);
                    Class.forName(DRIVER_NAME);
                    connection=DriverManager.getConnection(HOST, USER, PASSWD);
                    System.out.println(QtUsername+"************QtUsername");
                    System.out.println(QtPasswd+"************QtPasswd");
                    System.out.println(judgeUsernameExistenceSqlQuery);
                    System.out.println("连接数据库成功！");
                    statement=connection.createStatement();
                     resultSet=statement.executeQuery(judgeUsernameExistenceSqlQuery);
                     if(resultSet.next()){
                         if(resultSet.getString("passwd").equals(QtPasswd)){
                            System.out.println("密码匹配");
                            return "1";

                         }
                     }
                } catch (ClassNotFoundException classNotFoundException) {
                    System.out.println("加载MySQL驱动失败");
                  }
                  catch (SQLException sqlException){
                    System.out.println("SQL语句执行错误！");
                  }
                  finally{
                    statement=null;
                    resultSet=null;
                  }
                return "0";
            }
        };
        FutureTask futureTask=new FutureTask(callable);
        new Thread(futureTask).start();
        try {
            UserLogin.flag=futureTask.get().toString();
            
            
        } catch (ExecutionException executionException) {
            }
          catch (InterruptedException interruptedException){

            }
        return UserLogin.flag;
    }

    public static String setUsername(String USERNAME){
        infoUsername=USERNAME;
        return infoUsername;
    }

    public static String setPasswd(String Passwd){
        infoPasswd=Passwd;
        return "ok";
    }

    public static String printUserInfo(String parm){
        System.out.println(infoUsername);
        System.out.println(infoPasswd);
        return "ok";
    }

    public static String callgetConnectDatabase(String parm){ 
        return getConnectDatabase(null,null);
    }



}
