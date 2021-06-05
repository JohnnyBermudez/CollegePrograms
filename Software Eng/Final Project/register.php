<?php  session_start(); ?>

<!DOCTYPE html>
<html>

<!--Register Page-->
    <head>
        <title>Register</title>
        <link rel="stylesheet" href="css/main.css" />

    </head>

    <?php

 // checks if register button is pressed
 /*
 Intent: Create a student account 
 
 Precondition: The user needs to click on the register button
 
 Postcondition: A new text file will be generated for the  student user
 and added to the "accounts" directory
 
 */
    
    if(isset($_POST['register']))
    {
        //register, store information in values name, email, and password

        $name = $_POST['name'];
        $email = $_POST['email'];
        $password = $_POST['password'];
        
        //creates a student account, the account created is named after the email, and it is stored in the 
        // the fopen function opens a new file, and the w allows writing in the file
        // display error if a file cannot be opened
        $myfile = fopen("accounts/std_".$email.".txt", "w") or die("Unable to open file!");
        
        // this shows the way the textfile is storing data in the form of a table
        // we can choose to write in the classes, but we are not going to because we do not want students graduating without their prerequisites
        $txt = "NAME=".$name.",PASSWORD=".$password."\n";
        fwrite($myfile, $txt);
        fclose($myfile);

echo "<p align='left'> <font color=blue  size='3pt'>Congrats! You are now registered and ready to enroll in some classes!</font> </p>";
    
    }
    
  //End register



    ?>

    <body>


          <!--Previous Navigation Bar-->
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
        <!--Navbar Ends-->


        <div class="contactUsGridContainer" style="">


            <div class="contactUSContent btnContact">
                <h1 class="tc">Register</h1>

                <form class="login-form" method="post" action="register.php">


                    <table>

                        <tbody>

                            <tr>

                                <td>

                                    <label>Student Name</label>


                                </td>

                                <td>

                                    <input type="text" placeholder="Name" name="name" />


                                </td>

                            </tr>


                            <tr>

                                <td>

                                    <label>Username</label>


                                </td>

                                <td>

                                    <input type="text" placeholder="Username" name="email" />


                                </td>

                            </tr>

                            <tr>

                                <td>

                                    <label>Password</label>


                                </td>

                                <td>

                                    <input type="password" placeholder="Password" name="password" />


                                </td>

                            </tr>



                            <tr>
                                <td>
                                    <input type="submit"  name="register" value="Register" />
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



            </div>



        </div>


        <!--Footer-->









    </body>








</html>