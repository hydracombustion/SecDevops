
# Resource Injection

A resource injection issue occurs when the program allow user input to control resource identifiers such as network information (port number, network resource), storage access, or other resource configurations.
It could enable an attacker to access or modify otherwise protected system resources. The program may give the attacker the ability to transmit sensitive information to a third-party server.

> Warning: not to be confused with Path manipulation vulnerabilities where the attacker change the path and inject his exploit from his server. 

## Example of No Compliant code:
```
  String rPort = request.getParameter(argv[1]); 
  ... 
  ServerSocket srvr = new ServerSocket(rPort); 
  Socket skt = srvr.accept();  ...
```
or 
```
  String rPort = getenv(argv[1]); 
  ... 
  ServerSocket srvr = new ServerSocket(rPort); 
  Socket skt = srvr.accept();  ...
```

## Compliant code:
```
  String rPort = request.getParameter(argv[1]);
  switch (rPort)
  {
    case "1234" : ServerSocket srvr = new ServerSocket(rPort);   -----> CONTROL PORT NUMBER
    default : printf(" Access Denied: the port is not authorized \n");
  }
  Socket skt = srvr.accept();  ...
```

# Remediations
* Do not allow a user or untrusted data to define sensitive parameters. 
* sanitize the input parameter
* Control the input data with a white list of port for example or other controls. 
* Verify that environment variable is secure. If you use getenv() with a static argument, check that this environnement variable can not be modify,read by an attacker. 
* Do not allow the user to manipulate the environnement variable.  

Views this link for further informations: https://owasp.org/www-community/attacks/Resource_Injection

