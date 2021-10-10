int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int dp[n+1][amount+1];
        if(amount==0)
            return 0;
        else
        {
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<amount+1;j++)
            {
                if(i==0)
                    dp[i][j]=INT_MAX-1;
                else if(j==0)
                    dp[i][j]=0;
                else if(i==1)
                {
                    if(j%coins[0]==0)
                        dp[i][j]=j/coins[0];
                    else
                        dp[i][j]=INT_MAX-1;
                }
                else
                {
                    if(coins[i-1]<=j)
                        dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                    else
                        dp[i][j]=dp[i-1][j];
                }
            }
        }
        }
            if (dp[n][amount]>INT_MAX-3)
                return -1;
            else
                return dp[n][amount];
        } 
