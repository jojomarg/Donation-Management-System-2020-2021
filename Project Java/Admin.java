class Admin extends User
{
    //Πεδία
    private static boolean isAdmin = true;

    //Admins Constractor 
    public Admin(String n, String p)
    {
        name = n;
        phone = p;
    }

    public boolean getIsAdmin()
    {
        return isAdmin;
    }
}