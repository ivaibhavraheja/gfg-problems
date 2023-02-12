class Solution{
private:
    bool checkPrime(int n){
        if (n == 1)
            return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i <= sqrt(n); i += 6){
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
    int nearestPrime(int n){
        int prime1, prime2;
        if(n == 1)
            return 2;
        for(int i=n; i>1; i--){
            if(checkPrime(i)){
                prime1 = i;
                break;
            }
        }
        for(int i=n; i<n*n; i++){
            if(checkPrime(i)){
                prime2 = i;
                break;
            }
        }
        if(abs(n-prime1) > abs(n-prime2))
            return prime2;
        else if(abs(n-prime1) < abs(n-prime2))
            return prime1;
        else
            if(prime1 < prime2)
                return prime1;
            else
                return prime2;
    }
    
public:
    Node *primeList(Node *head){
        Node* temp = head;
        while(temp != NULL){
            if(!checkPrime(temp->val)){
                int new_val = nearestPrime(temp->val);
                temp->val = new_val;
            }
            temp = temp->next;
        }
        return head;
    }
};
