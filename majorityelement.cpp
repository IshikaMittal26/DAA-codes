int getMajority(int x[], int n)
{
int majorityElement = 0;
for (int currBit = 0; currBit < 32; currBit = currBit + 1)
{
int countOnes = 0;
for (int i = 0; i < n; i = i + 1)
{

if ((x[i] & (1 << currBit)) != 0) 
countOnes = countOnes + 1;
}
if (countOnes > n / 2)
majorityElement = majorityElement (1 << currBit);

}

return majorityElement;
}
