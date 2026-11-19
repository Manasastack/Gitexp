# Gitexp
Project with git management
this is exp4

exp8
ise@ise-OptiPlex-3070:~/manasa_gitlab/experiment8$ git init
Initialized empty Git repository in /home/ise/manasa_gitlab/experiment8/.git/
ise@ise-OptiPlex-3070:~/manasa_gitlab/experiment8$ git clone https://github.com/Manasastack/Gitexp.git
Cloning into 'Gitexp'...
remote: Enumerating objects: 10, done.
remote: Counting objects: 100% (10/10), done.
remote: Compressing objects: 100% (6/6), done.
remote: Total 10 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (10/10), done.
ise@ise-OptiPlex-3070:~/manasa_gitlab/experiment8$ cd Gitexp
ise@ise-OptiPlex-3070:~/manasa_gitlab/experiment8/Gitexp$ git branch -a
* main
  remotes/origin/HEAD -> origin/main
  remotes/origin/Manasastack-patch-1
  remotes/origin/main
ise@ise-OptiPlex-3070:~/manasa_gitlab/experiment8/Gitexp$ git checkout master
error: pathspec 'master' did not match any file(s) known to git.
ise@ise-OptiPlex-3070:~/manasa_gitlab/experiment8/Gitexp$ git fetch origin
ise@ise-OptiPlex-3070:~/manasa_gitlab/experiment8/Gitexp$ git log --oneline origin/Manasastack-patch-1
01fa9bc (origin/Manasastack-patch-1) Add experiment 5 to something
97181de Update README.md
4745556 Initial commit
ise@ise-OptiPlex-3070:~/manasa_gitlab/experiment8/Gitexp$ git cherry-pick 97181de
On branch main
Your branch is up to date with 'origin/main'.

You are currently cherry-picking commit 97181de.

nothing to commit, working tree clean
The previous cherry-pick is now empty, possibly due to conflict resolution.
If you wish to commit it anyway, use:

    git commit --allow-empty

Otherwise, please use 'git reset'
ise@ise-OptiPlex-3070:~/manasa_gitlab/experiment8/Gitexp$ git log --oneline
5a2252b (HEAD -> main, origin/main, origin/HEAD) Merge pull request #1 from Manasastack/Manasastack-patch-1
01fa9bc (origin/Manasastack-patch-1) Add experiment 5 to something
97181de Update README.md
4745556 Initial commit
ise@ise-OptiPlex-3070:~/manasa_gitlab/experiment8/Gitexp$ git status
On branch main
Your branch is up to date with 'origin/main'.

You are currently cherry-picking commit 97181de.
  (all conflicts fixed: run "git cherry-pick --continue")
  (use "git cherry-pick --abort" to cancel the cherry-pick operation)

nothing to commit, working tree clean
ise@ise-OptiPlex-3070:~/manasa_gitlab/experiment8/Gitexp$ 
