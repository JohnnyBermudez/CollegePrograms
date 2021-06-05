<?php  session_start(); ?> <!-- Start Login Session -->

<!DOCTYPE html>
<html>

<!-- Contains the title of the page, also adds a reference main, to the css file-->
    <head>
        <title>Login</title>
        <link rel="stylesheet" href="main.css" />


    </head>



    <body>
        
         <!--
         Intent: Verify if user is a student or administrator
         
         Precondition: Open all text files and compare username and password values
         
         Postcondition: If username and password belong to a registered user then begin the user session, otherwise display error message
         
         The following code will execute when the Login button is pressed.
         If nothing is input then the error message is displayed as well
      
         -->

        <?php


        if(isset($_POST['login']))
        {
// variables for username and password
// the post method is used because it secures user information
            $username = $_POST['username'];
            $password = $_POST['password'];
            $type = $_POST['type'];
            
            //checks if a user is a student or faculty
            //then add .txt to open that text file
            //std_is for a student account and fac_ is for faculty a account
            
            if($type=="student")
            {
                $username = "std_".$username.".txt";
            }
            else if($type=="faculty")
            {
                $username = "fac_".$username.".txt";
            }

            
            // get all the .txt files of accounts, store it in directory
            $text="";
            $directory = './accounts';
            
            // scans the accounts, which are stored in directory, the information is set in an array
            $accounts = array_diff(scandir($directory), array('..', '.'));

            // begin for loop, look for the value that matches the username of the text file
            foreach($accounts as $value)
            {


                //checks if username is matched to a particular account
                if($value == $username)
                {
                    // open the account file and read from the beginning, otherwise there is an error
                    $myfile = fopen("accounts/".$username, "r") or die("Error occured while login");
                // grab the lines of text until the end of the file is reached
                    while(!feof($myfile))
                    {
                        $text = fgets($myfile) . "<br>";
                    }

                    fclose($myfile);

                }


            }//end for loop
            
            // seperate the contents in the array by a comma, string, string, etc, the if statement checks if the value beginning in the array is null
            // the text file data is formatted like a table, seperated by commas that only html and php can see, but cannot be seen by the textfile
            // arr[1] refers to the column holding username and password values
            /*
            The text file stores values in the following format
             username, password, courses
            Imagine it forming a table, with a column and rows
            */
            $arr  = explode(',',$text);
            if(isset($arr1[1]))
            {

            }


            //match the passwrord entered with a value in the account text file.
            // The text file has been broken into an array
        
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

            //show results, if the username matched a value in the text file:
            if($matches)
            {
                //login and set session of user
                // HTML does not maintain user state, this sets the session of the user currently logged in
                $_SESSION['type'] = $type;
                $_SESSION['username'] = $username;
                 header("location: "."profile.php");
            }
            else
            {
                // display error message

             echo "<p align='center'> <font color=red  size='4pt'>Error! Please log in again</font> </p>";
              
            }

        }



        ?>

<!-- https://www.youtube.com/watch?v=OWNxUVnY3pg&t=390s navigation and login page-->

<!--Navigation bar used to link pages and maintain session states--> 
        <!--Navbar Start-->
        <div id='nav' class="navv">
            <ul id='navigation'>
                <li class='logo'><a href='index.php'>Student Advising System</a></li>
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
                <h1 class="tc">LOGIN</h1>
 <!-- Php action submits information to url at the initial index page-->
                <form class="login-form" method="post" action="index.php">
                    
<!-- form for inputting username, password-->

                    <table>

                        <tbody>

                            <tr>

                                <td>

                                    <label>Username</label>


                                </td>

                                <td>
                     <!-- username value-->
                                    <input type="text" placeholder="Username" name="username" />


                                </td>

                            </tr>

                            <tr>

                                <td>

                                    <label>Password</label>


                                </td>

                                <td>
                            <!-- password value-->
                                    <input type="password" placeholder="Password" name="password" />


                                </td>

                            </tr>

                            <tr>

                                <td>

                                    <label>Login As</label>


                                </td>

                                <td>

                                    <select name="type">
                                    <!-- student and faculty values-->
                                        <option value="student">Student</option>
                                        <option value="faculty">Faculty</option>

                                    </select>


                                </td>

                            </tr>

                            <tr>
                                <td>
                                    <!-- navigates to register page-->
                                    <a href="register.php">Register</a>
                                </td>
                            </tr>  

                            <tr>
                                <td>
                                    <!--login value and button, start of validation-->
                                    <input type="submit"  name="login" value="Login" />
                                </td>
                            </tr>    

                        </tbody>


                    </table>

                </form>

            </div>


        </div>

        <!--Footer-->


        <div class="footer" >
            <div class="FooterText">

           <!--  /   <p>&copy; 2018. All right Reserved</p>-->


            </div>



        </div>


        <!--Footer-->




    </body>




</html>
