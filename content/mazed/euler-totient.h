/**
 * Author: Mazed
 * Date:
 * License:
 * Source:
 * Description: euler totient.
 * Time: $O(n log log n)$
 * Status: Tested
 */
const int nmax = 1e6;
int phi[nmax+5];
bool mark[nmax+5];
void euler_totient(){
    for(int i=1; i<=nmax; i++){
        phi[i]=i;
    }
    for(int i=2; i<=nmax; i++){
        if(mark[i]) continue;

        for(int j=i; j<=nmax; j+=i){
            phi[j] = phi[j] - phi[j]/i;
            mark[j]=true;
        }
    }
}
