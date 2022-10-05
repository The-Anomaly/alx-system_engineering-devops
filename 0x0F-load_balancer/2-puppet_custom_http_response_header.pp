# Automation: creates a custom HTTP header response with Puppet.
exec { 'command':
  command  => 'apt-get -y update;
  apt-get -y install nginx;
  sudo sed -i "/server_name _;/a add_header X-Served-By $HOSTNAME;" /etc/nginx/sites-enabled/default;
  service nginx restart',
  provider => shell,
}
