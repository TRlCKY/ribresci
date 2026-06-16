*This project has been created as part of the 42 curriculum by **ribresci***

📘 Virtual Machine Configuration – README
##📌 RULES

The hostname of your virtual machine must be your login ending with 42 (ribresci42).
You will have to modify this hostname during your peer review.

You have to implement a strong password policy.

You have to install and configure sudo following strict rules.

In addition to the root user, a user with your login as username has to be present.

This user has to belong to the user42 and sudo groups.

##🔐 PASSWORD POLICY
Check Password Settings
sudo chage -l username


If values do not correspond to the required figures, they must be changed manually as follows:

Password Expiration

Password must expire every 30 days:

sudo chage -M 30 <user>


Minimum number of days before password modification: 2 days

sudo chage -m 2 <user>


Warning message 7 days before expiration:

sudo chage -W 7 <user>

Password Requirements

At least 10 characters long

Must contain:

1 uppercase letter

1 lowercase letter

1 number

Must not contain more than 3 consecutive identical characters

Must not include the name of the user

The following rule does not apply to the root password:

Password must have at least 7 characters different from the former password

Root password must comply with the policy

##🔑 Password Configuration Files
sudo nano /etc/security/pwquality.conf

##Settings:

minlen = 10
dcredit = -1
ucredit = -1
lcredit = -1
maxrepeat = 3
usercheck = 1
dfok = 7
sudo nano /etc/pam.d/common-password

##👤 USERS INFORMATION

Domain name: ribresci42

User account: ribresci42

User password: bobby

Encryption passphrase: bobby

Root password: bobby

##🖥️ HOSTNAME CONFIGURATION

Change hostname:

sudo hostname

Edit hosts file:

sudo nano /etc/hosts

Check hostname:

hostnamectl

##🧑‍💻 USER MANAGEMENT
Create New User
sudo adduser new_username

Add User to Groups
sudo usermod -aG user42 your_username
sudo usermod -aG evaluating your_new_username

Check groups:

getent group user42
getent group evaluating

##Useful User Commands
useradd        # creates a new user
usermod        # modifies user parameters (-l, -c, -g)
userdel -r     # deletes user and associated files
id -u          # displays user ID
users          # shows logged-in users
cat /etc/passwd | cut -d ":" -f 1
cat /etc/passwd | awk -F '{print $1}'

##👥 GROUP MANAGEMENT
groupadd       # creates a new group
gpasswd -a     # adds user to group
gpasswd -d     # removes user from group
groupdel       # deletes group
groups         # displays user groups
id -g          # shows main group ID
getent group   # lists users in a group

##🔒 SUDO CONFIGURATION

Edit sudoers file:

sudo nano /etc/sudoers

Require tty

Why use tty?
If some non-root code is exploited (a PHP script, for example), the requiretty option prevents exploit code from directly upgrading privileges by running sudo.

##🔍 CHECK SYSTEM STATUS
sudo ufw status
sudo service sshd status
getent group
cut -d: -f1 /etc/passwd
hostnamectl

-aa status(check apparmor)

##⏰ CRONTAB

A crontab file contains instructions for the cron(8) daemon:

“Run this command at this time on this date.”

Edit root crontab:

sudo crontab -u root -e

Example:

*/10 * * * * sh /home/ribresci/monitoring.sh

🌐 SSH CONNECTION
ssh ribresci42@localhost -p 4241

🔌 PORTS

HOSTPORT: 4241

GUESTPORT: 4242
