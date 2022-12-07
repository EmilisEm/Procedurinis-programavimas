printf("The domain of the email is: ");
    for (i = 0; i < strlen(email); ++i)
    {
        if (afterAt)
        {
            printf("%c", email[i]);
            continue;
        }
        if (email[i] == '@')
        {
            afterAt = 1;
        }
    }
    printf("\n");