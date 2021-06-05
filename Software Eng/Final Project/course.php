<?php  session_start(); 

if(!isset($_SESSION['type']))
{
    header("location: "."index.php");
}

?>

<!DOCTYPE html>
<html>
 
 <!--Course Page Created for link navigation of student course descriptions-->
    <head>
        <title>Course</title>
        <link rel="stylesheet" href="css/main.css" />


    </head>



    <body>


        <?php
// Same as in Index page, finds the students log

        if(isset($_POST['login']))
        {

            $username = $_POST['username'];
            $password = $_POST['password'];
            $type = $_POST['type'];

            if($type=="student")
            {
                $username = "std_".$username.".txt";
            }
            else if($type=="faculty")
            {
                $username = "fac_".$username.".txt";
            }


            $text="";
            $directory = './accounts';
            $accounts = array_diff(scandir($directory), array('..', '.'));

            foreach($accounts as $value)
            {//for



                if($value == $username)
                {

                    $myfile = fopen("accounts/".$username, "r") or die("Error occured while login");

                    while(!feof($myfile))
                    {
                        $text = fgets($myfile) . "<br>";
                    }

                    fclose($myfile);




                }




            }//for
            $arr  = explode(',',$text);
            if(isset($arr1[1]))
            {

            }



            $searchthis = $password;
            $matches = array();

            $handle = @fopen("accounts/".$username, "r");
            if ($handle)
            {
                while (!feof($handle))
                {
                    $buffer = fgets($handle);
                    if(strpos($buffer, $searchthis) !== FALSE)
                        $matches[] = $buffer;
                }
                fclose($handle);
            }

            //show results:
            if($matches)
            {
                echo "LOGED IN";
            }
            else
            {
                echo "INVALID CREDENTIALS";
            }

        }



        ?>



      <!--Navbar Start-->
        <div id='nav' class="navv">
            <ul id='navigation'>
                <li class='logo'><a href='index.php'>Student System</a></li>
                <li class='navigation-Contact'><a href='index.php'>Login</a></li>
                <li class='navigation-Contact'><a href='register.php'>Register</a></li>
                <?php  if(isset($_SESSION['type'])){ ?>
                <li class='navigation-Contact'><a href='profile.php'>Profile</a></li>
                <?php } ?>
           
                <?php  if(isset($_SESSION['type'])){ ?>
                <li class='navigation-Contact'><a href='logout.php'>Logout</a></li>
                <?php } ?>


            </ul>
        </div>
        <!--Navbar End-->








        <div class="contactUsGridContainer" style="">


            <div class="contactUSContent btnContact">
                <h1 class="tc">Course</h1>

                <?php
                    $value = $_GET['n'];
                    $value = str_replace("<br>","",$value);
                
                $myfile = fopen("courses/".$value.".txt", "r") or die("Error occured while login");
                
                while(!feof($myfile))
                {
                     echo $text = fgets($myfile) . "<br>";
                }

                fclose($myfile);
                 
                    
                   
                ?>

            </div>


        </div>

        <!--Footer-->


        <div class="footer" >
            <div class="FooterText">

                


            </div>



        </div>


        <!--Footer-->









    </body>








</html>