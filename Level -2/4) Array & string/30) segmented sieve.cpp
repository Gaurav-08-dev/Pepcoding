 private static ArrayList<Integer> sieve(int n) {
        boolean[] isprime = new boolean[n + 1];

        for(int i = 2; i * i <= n; i++) {
            if(isprime[i] == true) 
                continue;
            
            for(int j = i + i; j <= n; j += i) 
                isprime[j] = true;
        }

        ArrayList<Integer> ans = new ArrayList<>();
        for(int i = 2; i <= n; i++) {
            if(isprime[i] == false) {
                ans.add(i);
            }
        }
        return ans;
    }

    // segmented sieve
    public static void segmentedSieveAlgo(int a, int b) {
        int rootb = (int)Math.sqrt(b);
        ArrayList<Integer> primes = sieve(rootb);
        // prime[i] = false, i is prime

        boolean[] isprime = new boolean[b - a + 1];
        // isprime[i] == false -> i is prime number
        
        for(int prime : primes) {
            int multiple = (int)Math.ceil((a * 1.0) / prime);

            if(multiple == 1) multiple++;

            int si = multiple * prime - a;
            for(int j = si; j < isprime.length; j += prime) {
                isprime[j] = true; // j is not prime
            }
        }

        for(int i = 0; i < isprime.length; i++) {
            if(isprime[i] == false && i + a != 1) {
                // value = index + base value
                int val = i + a;
                System.out.println(val);
            }
        }
    }