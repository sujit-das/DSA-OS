#General Tips
How to create SSH keys
----------------------
1. Check for existing SSH keys - cd ~/.ssh , ls -la OR ls id_*
2. Backup old keys - mkdir key_backup , cp id_rsa* key_backup
3. Generate a new key - 
   ssh-keygen -t rsa -C "to.sujitdas@gmail.com"
   no pass phrase selected / hit enter
4. cat yes.pub   / this is the public key generated, content needs to be copied and pasetd into bitbucket

------------------------------

You can use the git config to enable credentials storage in git.

git config --global credential.helper store
---------------------------------
Command to set git user name and paassword:
git config --global user.name "Sujit Das"
git config --global user.email "to.sujitdas@gmail.com"
---------------------------------
Command to clone: git clone git@github.com:sujit-das/LibAlgo.git

# LibAlgo
To compile: c++ <file_name> 
