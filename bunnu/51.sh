awk '{
     c += length;
     w += NF;
     l++;
}

END { 
    print "no of char :", c;
    print "no of words :", w;
    print "no of lines :", l;
}' demo.txt

