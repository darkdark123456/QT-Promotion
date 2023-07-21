/*
 * @author: MENG ZHEN CHUAN
 * @date: do not edit
 * @description: HADOOP Project
 * @method: note
 */
package com.javaForcpp;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;


// 腾讯云公网 IP 111.230.112.186


public class jdbcForCplusCplus{

    public static String DRIVER_NAME = "com.mysql.jdbc.Driver";
    public static String HOST = "jdbc:mysql://111.230.112.186:3306/usrinfo";
    public static String USER = "MENG";
    public static String PASSWD = "123456";

    public static String infoUsername;
    public static String infoPasswd;
    public static String infoRegisterCode;

    public static Connection connection=null;
    public static Statement  statement=null;
    public static ResultSet  resultSet=null;


    public static int TempCodesum=0;
    public static boolean TempCodeflag=false;
    public static String registerFlag="0";


    public static int getConnectDatabase() {
        getConnectDatabase(null,null);
        return 1;
    }

    public static String getConnectDatabase(String Username,String Passwd){
        System.out.println("****************ok*************");
        new Thread(){
           @Override
           public void run(){
               String tUsername=jdbcForCplusCplus.infoUsername;
               String tPasswd=jdbcForCplusCplus.infoPasswd;
               String judgeUsernameExistenceSqlQuery=String.format("select * from userdata where username=%s",tUsername);
               String SQL_QUERY=String.format("insert into userdata(username,passwd) values('%s','%s')",tUsername ,tPasswd);
               System.out.println(SQL_QUERY);
            try{
                Class.forName(DRIVER_NAME);
                System.out.println("加载MySQL驱动成功");
                connection=DriverManager.getConnection(HOST, USER, PASSWD);
                System.out.println("连接数据库成功！");
                statement=connection.createStatement();

                getRegisterCode(statement);

                String TEMP_CODE=judgeRgcodeAndInfoRgCode();
                if(TEMP_CODE != null){
                  System.out.println("***************激活成功********************");
                  ++TempCodesum;
                  if(TempCodesum<=5000){
                    String SQL_UPDATE=String.format("update registercode set codesum=%d where code='%s'", TempCodesum,TEMP_CODE );
                    statement.executeUpdate(SQL_UPDATE);
                    jdbcForCplusCplus.setActivationFlag("1");
                  }
                  else{
                    System.out.println("没有从数据库中获得注册码");
                    jdbcForCplusCplus.setActivationFlag("0"); //没有激活
                    return;
                  }
                  resultSet=null;
                  resultSet=statement.executeQuery(judgeUsernameExistenceSqlQuery);
                  if(resultSet.next()){
                     return;
                 }
                  statement.executeUpdate(SQL_QUERY);
                  System.out.println("插入数据成功！");
                  System.out.println("jdbcForCplusCplus.registerFlag  "+jdbcForCplusCplus.registerFlag);
                 
                }
                else{System.out.println("***************激活码错误，激活失败,正在返回！********************");
                    return;
                }

            }   catch(ClassNotFoundException classNotFoundException){
                System.out.println("加载MySQL驱动失败");
            }   catch(SQLException sqlException){
                System.out.println("SQL语句执行错误！ 即将返回");
            }   finally{
                    statement=null;
                    resultSet=null;
                }
           }

        }.start();
        return jdbcForCplusCplus.registerFlag;
        }

    public static String infoSignalParma(String username){
        System.out.println("**********************"+infoUsername);
        System.out.println("**********************"+infoPasswd);
        return "ok";
}

    public static String setInfoRegisterCode(String INFO_REGISTERCODE){
        infoRegisterCode=INFO_REGISTERCODE;
        return "ok";
    }

    public static String setInfoUsername(String INFO_USERNAME){
        infoUsername=INFO_USERNAME;
        return "ok";
    }

    public static String setInfoPASSWD(String INFO_PASSWD){
        infoPasswd=INFO_PASSWD;
        getConnectDatabase(infoUsername, infoPasswd);
        return "ok";

    }

    public static String getRegisterCode(Statement statement){
        String judgeRegisterCodeMatchSqlQuery=String.format("select * from registercode");

        try {
            resultSet=statement.executeQuery(judgeRegisterCodeMatchSqlQuery);

        } catch (SQLException sqlException) {
            System.out.println("SQL语句执行错误");
        }

        return "ok";
    }

    public static String judgeRgcodeAndInfoRgCode(){
        try {
            System.out.println(infoRegisterCode);
            while(resultSet.next()){
                System.out.println(resultSet.getString("code"));
                if(resultSet.getString("code").equals(infoRegisterCode)){
                    TempCodesum=resultSet.getInt("codesum");
                    TempCodeflag=resultSet.getBoolean("codeflag");
                    System.out.println(TempCodesum);
                    System.out.println(TempCodeflag);
                    return infoRegisterCode;
                }
            }
            }  
        catch (SQLException sqlException) {
            System.out.println("*************SQL语句执行错误*************");
        }
        return null;
    }

    public static void setActivationFlag(String flag){
        registerFlag=flag;
    }

    public static String returnActivationFlag(String tempParm){
        return registerFlag;
    }  

}
