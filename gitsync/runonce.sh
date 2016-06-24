coding=https://git.coding.net/cruiser_ysw
github=https://github.com/34985086
oschina=https://git.oschina.net/cruiser_ysw
csdn=https://code.csdn.net/cruiser_ysw

repoName=$(basename $(pwd))

cp .git/config .git/config_bak

for account in $coding $github $oschina $csdn
do
    grep "$account" .git/config >/dev/null 2>&1
    
    if [ $? -eq 1 ]; then
        echo "[add new] : $account/$repoName.git"
        git remote set-url --add origin $account/$repoName.git
    else
        echo "[exist already] : $account/$repoName.git"
    fi
done

git push --all
  
