#include <stdio.h>
int main (int argc, char *argv[])
{
    int i, A[10], first, key, last, size, op2, temp, j, max, min, sum, elem, op, flag, count2, k, s, count;
    float av;


    flag=1;
    size=0;
    i=0;

    while (flag==1){ // flag αληθής

        printf(" 1. Add element\n 2. Search element\n 3. Delete element\n 4. Max\n 5. Min \n 6. Sum\n 7. Average\n 8. Sort array\n 9. Show array\n 0. Exit\n");
        printf("Choose an option:\n"); // εμφανίζω επαναληπτικά το μενού επιλογών
        scanf("%d", &op);
        if(op<0 || op>9){ // έλεγχος αν η επιλογή είναι έγκυρη 
            printf("YOU GAVE A WRONG OPTION. TRY AGAIN. CHOOSE BETWEEN 0-9.\n");
            scanf("%d", &op); // Αν δεν είναι σωστή ξανά δίνει τιμή
        }

        // αρχή επιλογών
        if (op==0){ // έξοδος
            flag=0; // flag ψευδής άρα τερματίζει το πρόγραμμα
        }
        else if(op==1){ // εισαγωγή

            if (i>=0 && i<=10){ // ελέγχω να μην ξεπερνά τα όρια του πίνακα
                printf("GIVE AN ELEMENT:\n");
                scanf("%d", &elem);
                A[i]=elem;
                printf("THE ELEMENT ADDED IN THE ARRAY\n");
                i++; // πηγάνει στην επόμενη θέση του πίνακα
                size++; // αυξάνω την μεταβλητή size για να ξέρω πόσα στοιχεία έχει ο πίνακας
            }

            else{
                printf("THE ARRAY IS FULL\n"); // έχουν ξεπεραστεί τα επιτρεπτά όρια
            }
        }

        else if(op==2){ // αναζήτηση

            printf("GIVE THE KEY:\n");
            scanf("%d", &key);

            count=0;
            for(i=0;i<=size-1;i++){ // έλενχος αν υπάρχει η τιμή στον πίνακα
                if (key == A[i]){
                    count++;
                }
            }
        
            if (count>=1){ // υπάρχει έστω μία φορά
                printf(" DO YOU WANT 1. THE FIRT 2. THE LAST OR 3. ALL THE POSITIONS %d IS FOUND?\n", key);
                scanf("%d", &op2);
                if(op2<1 || op2>3){ // έλεγχος σωστής επιλογής
                    printf("YOU GAVE A WRONG OPTION. TRY AGAIN. CHOOSE BETWEEN 1-3.\n");
                    scanf("%d", &op2);
                }

                if (op2==1){ // 1 φορά εμφάνισης
        
                    first=-1;
                    for(i=0;i<=size-1;i++){
                        if(A[i]==key){ // βρέθηκε 1η φορά
                            first=i;
                            i=size+1; // κάνω την συνθήκη ψευδή και σταματά
                        }
                    }    
                    printf("FOUND IN %d POSITION\n", first);
                }

                else if(op2==2){ // τευταία φορά εμφάνισης

                    for(i=0; i<=size-1; i++){
                        if (A[i]==key){
                            last=i; // βρέθηκε τελευταία φορά
                        }
                    }

                    printf("FOUND IN %d POSITION\n", last); 
                }

                else{ // όλες οι φορές εμφάνισης

                    for (i = 0; i <=size-1; i++) {
                       if (key == A[i]){ 
                            printf("FOUND IN:%d\n", i); 
                        }
                    }
                }
                
            }
            else{
                printf("THE ELEMENT DOESN'T EXIST\n");
            }   
        }
        else if(op==3){ // διαγραφή

            printf("GIVE THE KEY:\n");
            scanf("%d", &key);

            count2=0;
            for(i=0;i<=size-1;i++){
                if (key == A[i]){
                    count2++; // έλεγχος αν υπάρχει η τιμή στον πίνακα και πόσες φορές
                }
            }
            
            if(count2>=1){ // αν υπάρχει

                printf("YOU WANT TO DELETE 1. THE FIRST 2. THE LAST OR 3. ALL THE TIMES %d APPEARS?\n", key);
                scanf("%d", &op2);
                if(op2<1 || op2>3){ // έλεγχος σωστής επιλογής
                    printf("YOU GAVE A WRONG OPTION. TRY AGAIN. CHOOSE BETWEEN 1-3.\n");
                    scanf("%d", &op2);
                }

                if(op2==1){ // διαγραφή 1ης εμφάνισης
                    
                    first=-1; // αναζήτη 1ης εμφάνισης
                    for(i=0;i<=size-1;i++){
                        if(A[i]==key){
                            first=i;
                            i=size+1;
                        }
                    }

                    for(i=first;i<=size-1;i++){ 
                        // μεταφορά της επιλεγμένης τιμής στο τέλος του πίνακα ανάλογα πόσα στοιχεία έχει
                        temp=A[i];
                        A[i]=A[i+1]; // ολίσθηση των υπόλοιπων στοιχείων 1 θέση αριστερά
                        A[i+1]=temp;
                    }

                    size=size-1; // αφαιρώ μια τιμή απο το πλήθος των στοιχείων 
                    printf("THE FIRST TIME THE ELEMENT %d APPEARS IN THE ARRAY HAS BEEN DELETED.\n", key);
                }
                else if(op2==2){ // διαγραφή τελευταίας εμφάνισης

                    last=-1;
                    for(i=0; i<=size-1; i++){ //αναζήτηση τελευταίας φοράς εμφάνισης
                        if (A[i]==key){
                            last=i;
                        }
                    }
                    
                    for(i=last;i<=size-1;i++){ 
                        // μετφορά επιλεγμένης τιμής στο τέλος του πίνακα ανάλογα με το μέγεθος του
                        temp=A[i];
                        A[i]=A[i+1]; // ολίσθηση των υπόλοιπων στοιχείων 1 θέση αριστερά
                        A[i+1]=temp;
                    }

                    size=size-1; // μείωση του πληθούς των στοιχείων 
                    printf("THE LAST TIME THE ELEMENT %d APPEARS IN THE ARRAY HAS BEEN DELETED.\n", key);
                }
                else{ // διαγραφή της επιλεγμένης τιμής όσες φορές υπάρχει

                    s=size-1; // θέτω s το πλήθος στοιχείων που υπάρχουν στον πίνακα
                    for(k=0;k<=s;k++){ // κάνω επανάληψη τόσες φορές όσα τα στοιχεία
                        for(i=0;i<=s;i++){ 
                            if(A[i]==key){ // αν το στοιχείο του πίνακα είναι ίσο με την επιλεγμένη τιμή τότε
                                for(j=i;j<=s;j++){ // όσα στοιχεία βρίσκονται μετά απο την επιλεγμένη τιμή 
                                    temp=A[j]; //πηγαίνουν 1 θέση αριστερά και η επιλεγμένη τιμή  
                                    A[j]=A[j+1]; // μεταφέρεται στο τέλος του πίνακα
                                    A[j+1]=temp;
                                }
                                s--; // μειώνω το πλήθος κατα 1 όσες φορές μεταφέρω την επιλεγμένη τιμή για να μην κάνω περιττές επαναλήψεις
                            }
                        }
                    }
                    size=size-count2; // το αρχικό πλήθος μειώνεται τόσες φορές όσο το πλήθος των στοιχείων που ισούται με την επιλεγμένη τιμή
                    printf("THE ELEMENT %d HAS BEEN DELETED FROM THE ARRAY.\n", key);
                }
        
            }
            else{
                printf("THE ELEMENT DOESN'T EXIST\n");
            }

        }
        else if(op==4){ // εύρεση μεγαλυτέρου

            if(size!=0){ // αν έχω στοιχεία στον πίνακα

                max=A[0]; // θέτω μεγαλύτερο το 1ο
                for(i=1;i<=size-1;i++){ // απο το 2ο στοιχείο μέχρι το τελευταίο
                    if (A[i]>max){ // αν βρω τιμή μεγαλύτερη από αυτή που έθεσα 
                        max=A[i]; // τότε την βάζω στην max
                    }
                }
                printf("MAX:%d\n", max);
            }
            else{
                printf("THE ARRAY IS EMPTY\n");
            }
        }
        else if(op==5){ // εύρεση μικρότερου

            if(size!=0){ // αν υπάρχουν στοιχεία στον πίνακα

                min=A[0]; // ακολουθώ την ίδια διαδικασία με την εύρεση μεγαλύτερου
                for(i=1;i<=size-1;i++){
                    if(A[i]<min){
                        min=A[i];
                    }
                }
                printf("MIN:%d\n", min);
            }
            else{
                printf("THE ARRAY IS EMPTY\n");
            }
        }
        else if(op==6){ // άθροισμα

            sum=0; // ξεκινάω απο την τιμή 0 έτσι αν ο πίνακας δεν έχει στοιχεία το 
            for(i=0;i<=size-1;i++){ // προσθέτω όλα τα στοιχεία του πίνκα
                sum=sum+A[i];
            }
            printf("SUM:%d\n", sum);
        }
        else if(op==7){ // μέσος όρος

            sum=0; // βρίσκω το άθροισμα όλων των στοιχείων
            for(i=0;i<=size-1;i++){
                sum+=A[i];
            }
            if(size!=0){ // αν υπάρχουν στοιχεία στον πίνακα
                av=(float)sum/size; // μεττρέπω μια απο τις 2 μεταβλητές σε float επειδή μπορεί να έχω δεκαδικό μέρος
                printf("AVERAGE:%.3f\n", av); // και διαιρώ με size οχι size-1 
            }
            else{
                printf("THE ARRAY IS EMPTY\n");
            }
        }
        else if(op==8){ // ταξινόμηση

            if(size!=0){ // αν έχω στοιχεία στον πίνακα

                printf("CHOOSE BETWEEN 1.INCREASING OR 2.DECREASING SORT:\n");
                scanf("%d", &op2);
                if(op2<1 || op2>2){ // έλεγχος αν η επιλογή ειναι σωστή
                    printf("YOU GAVE A WRONG OPTION. TRY AGAIN. COOSE BETWEEN 1-2.\n");
                    scanf("%d", &op2);
                }

                if(op2==1){ // αύξουσα

                    for(i=1;i<=size-1;i++){ // ξενινώ απο το προτευταίο στοιχείο για να έχει νόημα η if
                        for(j=size-1;j>=i;j--){ // από το τέλος προς την αρχή συγκρίνω ολα τα στοιχεία του και
                            if(A[j-1]>A[j]){ // παίρνω ανα 2 τα ζευγάρια του πίνκα και τα συγκρίνω μεταξύ τους
                                temp=A[j-1]; // αν η τιμή ενός στοιχείου ειναι μεγαλύτερη από την επόμενη του
                                A[j-1]=A[j]; // αλλάζω θέσης τα στοιχεία ώστε αυτό με την μικρότερη τιμή
                                A[j]=temp; // να πηγαίνει στην αρχή του πίνακα
                            }
                        }
                    }
                }

                else if(op2==2){ // φθίνουσα

                    for(i=1;i<=size-1;i++){ // κάνω διαδοχικές συγκρίσεις στοιχείων ανα 2
                        for(j=size-1;j>=i;j--){ // ξεκινώντας όπως και με την άυξουσα απο το τέλος
                            if(A[j-1]<A[j]){ // αν ένα στοιχείο έχει τιμή μικρότερη απο την επόμενη
                                temp=A[j-1]; // τότε αλλάζω θέσεις τα στοιχεία και αυτό με την μεγαλύτερη τιμή
                                A[j-1]=A[j]; // πηγαίνει στην αρχή του πίνακα
                                A[j]=temp;
                            }
                        }
                    }
                }
            
            }
            else{
                printf("THE ARRAY IS EMPTY\n");
            }
        }
        else if(op==9){ // εμφάνιση

            if(size!=0){ // αν έχω στοιχεία στον πίνακα

                printf("ARRAY:\n");
                for(i=0;i<=size-1;i++){ // εμφανίζω όλα τα στοιχεία
                    printf("%d~", A[i]);
                }
                printf("\n");

            }
            else{
                printf("THE ARRAY IS EMPTY\n");
            }

        } // τέλος επιλογών
    

    } // flag ψευδής 

    return 0;

}
